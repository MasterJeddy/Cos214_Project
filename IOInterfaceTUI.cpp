//
// Created by maili on 2023/11/03.
//

#include "IOInterfaceTUI.h"
#include "Save.h"
#include "Load.h"
void IOInterfaceTUI::poll() {
  // std::cout << "What do you want to do" << std::endl;
  render();
  bool run = true;
  UserCommand *command;
  while (run)
  {
    command = queryUser();
    if (!command)
    {
      run = false;
    }
    else
    {
      commandLog->addEntry(command);
      command->execute();
      delete command;
    }
    render();
  }
}
void IOInterfaceTUI::render() {
  if (!checkFlag(DONT_DRAW_HELP))
  {
    std::cout << "What do you want to do?" << std::endl;
    std::cout << "1. Save to memory" << std::endl;
    std::cout << "2. Load from memory" << std::endl;
    std::cout << "3. Save to file" << std::endl;
    std::cout << "4. Load from file" << std::endl;
    std::cout << "5. Update" << std::endl;
    std::cout << "6. Toggle Log View" << std::endl;
    std::cout << "7. Toggle Help View" << std::endl;
    std::cout << "8. Hire Maitre D" << std::endl;
    std::cout << "9. Hire Waiter" << std::endl;
    std::cout << "A. Expand Floor" << std::endl;
    std::cout << "C. Hire Chef" << std::endl;
    std::cout << "D. Expand Kitchen" << std::endl;
    std::cout << "E. Buy Stock" << std::endl;
  }

  if (checkFlag(DRAW_LOG))
  {
    CommandLogIterator *it = commandLog->createIterator();
    for (it->first(); !it->isDone(); it->next())
    {
      switch (it->currentItem()->getType())
      {
      case COMMANDS::SAVE:
        std::cout << "Save" << std::endl;
        break;
      case COMMANDS::LOAD:
        std::cout << "Load" << std::endl;
        break;
      case COMMANDS::TOGGLE_HELP:
        std::cout << "Toggle Help" << std::endl;
        break;
      case COMMANDS::TOGGLE_LOG:
        std::cout << "Toggle Log" << std::endl;
        break;
      case COMMANDS::HIRE_MAITRE_D:
        std::cout << "Hire Maitre D" << std::endl;
        break;
      case COMMANDS::BUY_TABLE:
        std::cout << "Buy Table" << std::endl;
        break;
      case COMMANDS::EXPAND_FLOOR:
        std::cout << "Expand Floor" << std::endl;
        break;
      case COMMANDS::HIRE_WAITER:
        std::cout << "Hire Waiter" << std::endl;
        break;
      case COMMANDS::UPDATE:
        std::cout << "Update" << std::endl;
        break;
      case COMMANDS::EXPAND_KITCHEN:
        std::cout << "Expand Kitchen" << std::endl;
        break;
      case COMMANDS::HIRE_CHEF:
        std::cout << "Hire Chef" << std::endl;
        break;
      case COMMANDS::BUY_STOCK:
        std::cout << "Buy Stock" << std::endl;
        break;
      }
    }
    delete it;
  }
}

UserCommand *IOInterfaceTUI::queryUser() {
  char c;
  do
  {
    std::cin >> c;
    switch (c)
    {
    case '1':
    {
      return new Save(commandLog, logs);
    }
      break;
    case '2':
    {
      return new Load(commandLog, logs);
    }
      break;
    case '3':
    {
      std::string file;
      std::cin >> file;
      return new Save(commandLog, logs, &file);
    }
      break;
    case '4':
    {
      std::string file;
      std::cin >> file;
      return new Load(commandLog, logs, &file);
    }
      break;
    case '5':
    {
      return new Update(floorController, nullptr);
    }
      break;
    case '6':
    {
      return new ToggleLog(this);
    }
      break;
    case '7':
    {
      return new ToggleHelp(this);
    }
      break;
    case '8':
    {
      return new HireMaitreD(floorController);
    }
      break;
    case '9':
    {
      return new HireWaiter(floorController);
    }
      break;
    case 'A':
    {
      return new ExpandFloor(floorController);
    }
      break;
    case 'B':
    {
      return new BuyTable(floorController);
    }
    case 'C':
    {
      return new HireChef(kitchenController);
    }
    case 'D':
    {
      return new ExpandKitchen(kitchenController);
    }
    case 'E':
    {
      return new BuyStock(kitchenController);
    }
      break;
    case 'q':
    {
      return nullptr;
    }
      break;
    default:
    {
    }
      break;
    }
  } while (true);
}
