//===-- COS214_Project/TableComposite.cpp - TableComposite class implementation ------*- C++ -*-===//
//
// COS 214 Project.
//
//===----------------------------------------------------------------------===//
///
/// \file
/// This file contains the implementation of the Table class specific functions as well as the functions
/// declared by its parent class TableComponent, for example the add() function where a component can
/// be added to a table.
///
///
//===----------------------------------------------------------------------===//

#include "TableComposite.h"
#include "Free.h"
#include <random>

TableComposite::TableComposite(int id)
{
    // id was made a string such that we do not end up with a case where TableComposite and Customer do not end
    // up with the same Id. We will append a special character for each respective object in order to help avoid
    // any sort of confusion later down the line.
    this->tableState = new Free();
    this->bill = nullptr;

    this->type = TYPE_TABLECOMPOSITE;

    this->waiterId = ""; // this table has not yet been assigned to a waiter

    std::stringstream idStream;
    idStream << this->type << id;
    std::string tempy = idStream.str();
    this->id = tempy;

    // set the default max capacity of the table to 4 - one table can host 4 people
    this->maxCapacity = 4;

    this->numOfFinishedOrders =0;
}

TableComposite::~TableComposite()
{
    // delete table state pointer and set to null
    delete this->tableState;
    this->tableState = nullptr;

    // delete bill pointer and set to null
    delete this->bill;
    this->bill = nullptr;

    // clear all the TableComponent children pointers, memory clenup will be done by floor class
    this->children.clear(); // finally clear the vector of tableComponent pointers
}

void TableComposite::addComponent(TableComponent *component)
{
    int counter = 1; // this will count the number of tables we have combined - starts off at 1 because the parent
                     // table doesn't count as a child
    //  and is therefore not part of the children vector
    children.push_back(component);
    std::vector<TableComponent *>::iterator miki = children.begin();
    for (miki; miki < children.end(); miki++)
    {
        if ((*miki)->getType() == TYPE_TABLECOMPOSITE)
        {
            counter++;
        }
    }
    // maxCapacity is equal to 4 + 2*(number of tables - 1)
    this->maxCapacity = 4 + 2 * (counter - 1);

    // change the state of the table to occupied if a customer has sat down
    if (component->getType() == TYPE_CUSTOMER)
    {
        TableState *tempy = new Occupied();
        this->setTableState(tempy);
    }
}

void TableComposite::removeComponent(TableComponent *component)
{
    std::vector<TableComponent *>::iterator miki = children.begin();
    for (miki; miki < children.end(); miki++)
    {
        if ((*miki)->getId() == component->getId())
        {
            children.erase(miki);
            break;
        }
    }
    // this will recalculate the table capacity once a table has been removed
    int counter = 1;
    std::vector<TableComponent *>::iterator mihail = children.begin();
    for (mihail; mihail < children.end(); mihail++)
    {
        if ((*mihail)->getType() == TYPE_TABLECOMPOSITE)
        {
            counter++;
        }
    }

    this->maxCapacity = 4 + 2 * (counter - 1);
}

TableComponent *TableComposite::getChild(std::string id)
{
    for (TableComponent *child : children)
    {
        if (child->getId() == id)
        {
            return child;
        }
    }
    return NULL;
}

int TableComposite::getCapacity()
{
    return this->maxCapacity;
}

void TableComposite::setMaxCapacity(int capacity)
{
    this->maxCapacity = capacity;
}

TableState *TableComposite::getTableState()
{
    return this->tableState;
}

std::string TableComposite::getLabel()
{
    std::string resultLabel = "";
    std::string tableLabels = this->id;
    std::string customerLabels = "";
    for (TableComponent *component : this->children)
    {
        if (component->getType() == TYPE_TABLECOMPOSITE)
        {
            tableLabels += "+" + component->getId();
        }
        else
        {
            customerLabels += " " + component->getId();
        }
    }

    tableLabels += " " + this->tableState->getName();

    resultLabel = tableLabels + customerLabels;

    return resultLabel;
}

double TableComposite::getPayment()
{
    BillComponent *mainBill = new BillComposite("Main-Bill");

    for (Order *order : orders)
    {
        int num = order->orderNumber;
        BillComponent *temp = new SubBill("Order" + num, order->getPrice());
        mainBill->add(temp);
    }

    // set all of the tables to free state once the bill has been paid
    // this will transition the state from the bill state to the free state
    this->getTableState()->proceed(this);
    // this will set the state to the free state
    // this->setTableState(this->getTableState());
    // loop through all of the children and set
    // their state to the free state

    std::queue<TableComponent *> toRemove;

    for (TableComponent *child : children)
    {
        if (child->getType() == TYPE_TABLECOMPOSITE)
        {
            TableComposite *childTable = static_cast<TableComposite *>(child);
            childTable->getTableState()->proceed(this);
        }
        else
        {
            toRemove.push(child);
        }
    }

    while (!toRemove.empty())
    {
        removeComponent(toRemove.front());
        toRemove.pop();
    }

    // return the total amount of the entire bill
    return mainBill->getTotal();
}

bool TableComposite::isContainedInAnotherTable()
{
    if (this->tableState->getName() != "Free" && this->getChildren().size() == 0)
    {
        // means this table is a child of another table
        return true;
    }
    return false;
}

void TableComposite::setTableState(TableState *tableState)
{
    delete this->tableState;
    this->tableState = tableState;

    // // loop through all of the children
    // //  and then set all of their states
    for (TableComponent *child : children)
    {
        if (child->getType() == TYPE_TABLECOMPOSITE)
        {
            TableComposite *childTable = static_cast<TableComposite *>(child);
            childTable->setTableState(this->tableState->clone());
        }
    }
}

void TableComposite::assignWaiter(Waiter *waiter)
{
    this->waiterId = waiter->getId();
    this->attachObserver(waiter);
}

void TableComposite::request()
{
    for (Observer *observer : observerList)
    {
        // loop through the observer list
        if (observer->getType() == TYPE_WAITER && observer->getId() == waiterId)
        {
            // notify this waiter
            // proceed the state of the table
            if (this->getTableState()->getName() != "Bill")
            {
                this->getTableState()->proceed(this);
            }
            observer->notify(this);
            break;
        }
    }
}

void TableComposite::requestBill()
{
    // notify the waiter then pass in the bill so that the waiter can create a bill
    for (Observer *observer : observerList)
    {
        // loop through the observer list
        if (observer->getType() == TYPE_WAITER && observer->getId() == waiterId)
        {
            // notify this waiter
            // change the state to bill
            tableState->proceed(this);
            observer->notify(this);
            break;
        }
    }
}

void TableComposite::attachObserver(Observer *observer)
{
    observerList.push_back(observer);
}

void TableComposite::detachObserver(Observer *observer)
{
    std::vector<Observer *>::iterator miki = observerList.begin();
    for (miki; miki < observerList.end(); miki++)
    {
        if ((*miki)->getId() == observer->getId())
        {
            observerList.erase(miki);
            break;
        }
    }
}

bool TableComposite::acceptOrReject()
{

    // this function will generate a random boolean
    std::mt19937 rng(std::random_device{}());
    bool randomBoolean = std::uniform_int_distribution<>{0, 1}(rng);
    return randomBoolean;
}

std::vector<Order*> TableComposite::order()
{
  std::mt19937 rng(std::random_device{}());
    //find the number of customers at this table
    int counter = 0;
    for(TableComponent* child: this->getChildren()){
        if(child->getType()== TYPE_CUSTOMER){
            counter++;
        }
    }
    std::vector<Order*> temp; 
    for(int i = 0; i<counter; i++){
        Order* ordery = new Order(this->getId());
        ordery->wantsKetchup = std::uniform_int_distribution<>{0, 1}(rng);
    ordery->wantsMustard = std::uniform_int_distribution<>{0, 1}(rng);
    ordery->wantsMayo = std::uniform_int_distribution<>{0, 1}(rng);
    ordery->beefPatty = std::uniform_int_distribution<>{0, 1}(rng);
    ordery->chickenPatty = std::uniform_int_distribution<>{0, 1}(rng);
    ordery->veganPatty = std::uniform_int_distribution<>{0, 1}(rng);
    ordery->wantsLettuce = std::uniform_int_distribution<>{0, 1}(rng);
    ordery->wantsTomato = std::uniform_int_distribution<>{0, 1}(rng);
    ordery->wantsPickles = std::uniform_int_distribution<>{0, 1}(rng);
    temp.push_back(ordery);

    }

    // change state by calling the proceed function
    // tableState->proceed(this);
    // create an order and return it

    // Order *order = new Order(this->getId());

    //

    // order->wantsKetchup = std::uniform_int_distribution<>{0, 1}(rng);
    // order->wantsMustard = std::uniform_int_distribution<>{0, 1}(rng);
    // order->wantsMayo = std::uniform_int_distribution<>{0, 1}(rng);
    // order->beefPatty = std::uniform_int_distribution<>{0, 1}(rng);
    // order->chickenPatty = std::uniform_int_distribution<>{0, 1}(rng);
    // order->veganPatty = std::uniform_int_distribution<>{0, 1}(rng);
    // order->wantsLettuce = std::uniform_int_distribution<>{0, 1}(rng);
    // order->wantsTomato = std::uniform_int_distribution<>{0, 1}(rng);
    // order->wantsPickles = std::uniform_int_distribution<>{0, 1}(rng);

    // change the state to WaitingOnFood
    this->tableState->proceed(this);

    return temp;
}

Order *TableComposite::complexOrder()
{

    // change state by calling the proceed function
    tableState->proceed(this);
    // create an order and return it
    Order *order = new Order(this->getId());

    std::mt19937 rng(std::random_device{}());

    order->wantsKetchup = std::uniform_int_distribution<>{0, 10}(rng);
    order->wantsMustard = std::uniform_int_distribution<>{0, 10}(rng);
    order->wantsMayo = std::uniform_int_distribution<>{0, 10}(rng);
    order->beefPatty = std::uniform_int_distribution<>{0, 10}(rng);
    order->chickenPatty = std::uniform_int_distribution<>{0, 10}(rng);
    order->veganPatty = std::uniform_int_distribution<>{0, 10}(rng);
    order->wantsLettuce = std::uniform_int_distribution<>{0, 10}(rng);
    order->wantsTomato = std::uniform_int_distribution<>{0, 10}(rng);
    order->wantsPickles = std::uniform_int_distribution<>{0, 10}(rng);

    return order;
}

Order *TableComposite::ultraComplexOrder()
{

    // change state by calling the proceed function
    tableState->proceed(this);
    // create an order and return it
    Order *order = new Order(this->getId());

    std::mt19937 rng(std::random_device{}());

    order->wantsKetchup = std::uniform_int_distribution<>{0, 20}(rng);
    order->wantsMustard = std::uniform_int_distribution<>{0, 20}(rng);
    order->wantsMayo = std::uniform_int_distribution<>{0, 20}(rng);
    order->beefPatty = std::uniform_int_distribution<>{0, 20}(rng);
    order->chickenPatty = std::uniform_int_distribution<>{0, 20}(rng);
    order->veganPatty = std::uniform_int_distribution<>{0, 20}(rng);
    order->wantsLettuce = std::uniform_int_distribution<>{0, 20}(rng);
    order->wantsTomato = std::uniform_int_distribution<>{0, 20}(rng);
    order->wantsPickles = std::uniform_int_distribution<>{0, 20}(rng);

    return order;
}

void TableComposite::rejectedService()
{

    // change state to Busy by calling the hold function
    tableState->hold(this);
}

void TableComposite::eat(Order *order)
{
    this->orders.push_back(order); // add this to the order
    numOfFinishedOrders++;

    int counter = 0;
    for(TableComponent* child: this->getChildren()){
        if(child->getType()== TYPE_CUSTOMER){
            counter++;
        }
    }

    if(numOfFinishedOrders==counter){
        tableState->proceed(this);
    for (Observer *observer : observerList)
    {
        if (observer->getId() == waiterId)
        {
            // notfity this waiter
            observer->notify(this);
            break;
        }
    }
    }
}

std::vector<TableComponent *> TableComposite::getChildren()
{
    return this->children;
}
