cmake_minimum_required(VERSION 3.26.4)
project(Cos214_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cos214_Project main.cpp Clock.cpp Clock.h WaitingOnWaiter.h WaitingOnWaiter.cpp WaitingOnFood.h
WaitingOnFood.cpp Busy.h Busy.cpp Bill.h Bill.cpp TableComponent.h TableComponent.cpp  TableComposite.h
TableComposite.cpp TableState.h TableState.cpp Occupied.h Occupied.cpp Free.h Free.cpp Eating.h
Eating.cpp SubBill.h SubBill.cpp BillComponent.h BillComponent.cpp BillComposite.h BillComposite.cpp
IOInterface.cpp IOInterface.h UserCommand.cpp UserCommand.h UserCommand.h Commands.cpp Commands.h Update.cpp
Update.h Save.cpp Save.h Load.cpp Load.h CommandLog.cpp CommandLog.h SavedLog.cpp SavedLog.h Logs.cpp Logs.h
CommandLogIterator.cpp CommandLogIterator.h FloorController.cpp Floor.h Floor.cpp Waiter.h Waiter.cpp Customer.h Customer.cpp Observer.h Observer.cpp MaitreD.h MaitreD.cpp
        Order.h
        Burger.cpp
        Burger.h
        Kitchen.cpp
        Kitchen.h
        HeadChef.cpp
        HeadChef.h
        Chef.cpp
        Chef.h
        Clock.cpp
        Clock.h
        BakerChef.cpp
        BakerChef.h
        GarnishChef.cpp
        GarnishChef.h
        ButcherChef.cpp
        ButcherChef.h
        SauceChef.cpp
        SauceChef.h
        BakerChef.h
        BurgerBuns.cpp
        BurgerBuns.h
        BurgerBuns.h
        BurgerIngredient.cpp
        BurgerIngredient.h
        BurgerIngredient.h
        Ketchup.cpp
        Ketchup.h
        Tomato.cpp
        Tomato.h
        Mustard.cpp
        Mustard.h
        Mayo.cpp
        Mayo.h
        Lettuce.cpp
        Lettuce.h
        Pickles.cpp
        Pickles.h
        Patty.cpp
        Patty.h
        BeefPatty.cpp
        BeefPatty.h
        ChickenPatty.cpp
        ChickenPatty.h
        VeganPatty.cpp
        VeganPatty.h
        KitchenController.cpp KitchenController.h IOInterfaceTUI.cpp IOInterfaceTUI.h IOInterfaceGUI.cpp IOInterfaceGUI.h olcPixelGameEngine/olcPixelGameEngine.h KitchenSubject.cpp KitchenSubject.h olcPixelGameEngine/olcSoundWaveEngine.h)
add_subdirectory(GTest)
#[[target_link_libraries(Cos214_Project PRIVATE -lX11 -lGL -lpthread -lpng -lstdc++fs)]]
target_link_libraries(Cos214_Project PRIVATE user32 gdi32 opengl32 gdiplus Shlwapi dwmapi stdc++fs winmm)
