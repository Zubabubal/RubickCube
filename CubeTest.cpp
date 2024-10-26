#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "../CubeCopy/Cube.cpp"
using namespace std;

TEST(CubeTest, FillingAndPrintTest)
{
    Cube cube;

    // Заполняем куб с помощью FillingTheCube
    cube.FillingTheCube(cube);

    // Перенаправляем cout в строковый поток для проверки вывода функции print
    ostringstream output; 
    streambuf* oldCoutBuffer = std::cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    // Вызываем функцию print, чтобы вывести состояние куба
    cube.print();

    // Восстанавливаем стандартный вывод
    cout.rdbuf(oldCoutBuffer);

    // Ожидаемый вывод после заполнения куба функцией FillingTheCube
    string expectedOutput = 
        "B B B \n"
        "B B B \n"
        "B B B \n\n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n\n"
        "G G G \n"
        "G G G \n"
        "G G G \n\n";
    // Проверяем, что вывод функции print совпадает с ожидаемым
    EXPECT_EQ(output.str(), expectedOutput);
}

TEST(CubeTest, RightColumnMove_UpAndDown) {
    Cube cube;

    // Заполняем куб с помощью FillingTheCube
    cube.FillingTheCube(cube);

    // Выполняем движение "вверх"
    int selectTurn = 1;
    cube.RightColumnMove(cube, selectTurn);

    // Ожидаемое состояние после движения "вверх"
    std::string expectedOutputAfterUp =
        "B B W \n"
        "B B W \n"
        "B B W \n\n"
        "W W G   R R R   B Y Y   O O O   \n"
        "W W G   R R R   B Y Y   O O O   \n"
        "W W G   R R R   B Y Y   O O O   \n\n"
        "G G Y \n"
        "G G Y \n"
        "G G Y \n\n";

    // Перенаправляем cout для проверки состояния после движения "вверх"
    std::ostringstream upOutput;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(upOutput.rdbuf());
    cube.print();
    std::cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(upOutput.str(), expectedOutputAfterUp);

    // Выполняем движение "вниз"
    selectTurn = 2;
    cube.RightColumnMove(cube, selectTurn);

    // Ожидаемое состояние после движения "вниз" (должно совпадать с состоянием после заполнения куба)
    std::string expectedOutputAfterDown =
        "B B B \n"
        "B B B \n"
        "B B B \n\n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n\n"
        "G G G \n"
        "G G G \n"
        "G G G \n\n";

    // Перенаправляем cout для проверки состояния после движения "вниз"
    std::ostringstream downOutput;
    std::cout.rdbuf(downOutput.rdbuf());
    cube.print();
    std::cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(downOutput.str(), expectedOutputAfterDown);
}

TEST(CubeTest, LeftColumnMove_UpAndDown) {
    Cube cube;

    // Заполняем куб с помощью FillingTheCube
    cube.FillingTheCube(cube);

    // Выполняем движение "вверх"
    int selectTurn = 1;
    cube.LeftColumnMove(cube, selectTurn);

    // Ожидаемое состояние после движения "вверх"
    std::string expectedOutputAfterUp =
        "W B B \n"
        "W B B \n"
        "W B B \n\n"
        "G W W   R R R   Y Y B   O O O   \n"
        "G W W   R R R   Y Y B   O O O   \n"
        "G W W   R R R   Y Y B   O O O   \n\n"
        "Y G G \n"
        "Y G G \n"
        "Y G G \n\n";

    // Перенаправляем cout для проверки состояния после движения "вверх"
    std::ostringstream upOutput;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(upOutput.rdbuf());
    cube.print();
    std::cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(upOutput.str(), expectedOutputAfterUp);

    // Выполняем движение "вниз"
    selectTurn = 2;
    cube.LeftColumnMove(cube, selectTurn);

    // Ожидаемое состояние после движения "вниз"
    std::string expectedOutputAfterDown =
        "B B B \n"
        "B B B \n"
        "B B B \n\n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n\n"
        "G G G \n"
        "G G G \n"
        "G G G \n\n";

    // Перенаправляем cout для проверки состояния после движения "вниз"
    std::ostringstream downOutput;
    std::cout.rdbuf(downOutput.rdbuf());
    cube.print();
    std::cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(downOutput.str(), expectedOutputAfterDown);
}

TEST(CubeTest, HighRowMove_ClockwiseAndCounterclockwise) {
    Cube cube;

    // Заполняем куб с помощью FillingTheCube
    cube.FillingTheCube(cube);

    // Выполняем движение по часовой стрелке
    int selectTurn = 1;
    cube.HighRowMove(cube, selectTurn);

    // Ожидаемое состояние после вращения по часовой стрелке
    std::string expectedOutputAfterClockwise =
        "B B B \n"
        "B B B \n"
        "B B B \n\n"
        "R R R   Y Y Y   O O O   W W W   \n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n\n"
        "G G G \n"
        "G G G \n"
        "G G G \n\n";

    // Перенаправляем cout для проверки состояния после вращения по часовой стрелке
    std::ostringstream clockwiseOutput;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(clockwiseOutput.rdbuf());
    cube.print();
    std::cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(clockwiseOutput.str(), expectedOutputAfterClockwise);

    // Выполняем движение против часовой стрелки
    selectTurn = 2;
    cube.HighRowMove(cube, selectTurn);

    // Ожидаемое состояние после вращения против часовой стрелки (должно совпадать с состоянием после заполнения куба)
    std::string expectedOutputAfterCounterclockwise =
        "B B B \n"
        "B B B \n"
        "B B B \n\n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n\n"
        "G G G \n"
        "G G G \n"
        "G G G \n\n";

    // Перенаправляем cout для проверки состояния после вращения против часовой стрелки
    std::ostringstream counterclockwiseOutput;
    std::cout.rdbuf(counterclockwiseOutput.rdbuf());
    cube.print();
    std::cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(counterclockwiseOutput.str(), expectedOutputAfterCounterclockwise);
}

TEST(CubeTest, DownRowMove_ClockwiseAndCounterclockwise) {
    Cube cube;

    // Заполняем куб с помощью FillingTheCube
    cube.FillingTheCube(cube);

    // Выполняем движение по часовой стрелке
    int selectTurn = 1;
    cube.DownRowMove(cube, selectTurn);

    // Ожидаемое состояние после вращения по часовой стрелке
    std::string expectedOutputAfterClockwise =
        "B B B \n"
        "B B B \n"
        "B B B \n\n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "R R R   Y Y Y   O O O   W W W   \n\n"
        "G G G \n"
        "G G G \n"
        "G G G \n\n";

    // Перенаправляем cout для проверки состояния после вращения по часовой стрелке
    std::ostringstream clockwiseOutput;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(clockwiseOutput.rdbuf());
    cube.print();
    std::cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(clockwiseOutput.str(), expectedOutputAfterClockwise);

    // Выполняем движение против часовой стрелки
    selectTurn = 2;
    cube.DownRowMove(cube, selectTurn);

    // Ожидаемое состояние после вращения против часовой стрелки (должно совпадать с состоянием после заполнения куба)
    std::string expectedOutputAfterCounterclockwise =
        "B B B \n"
        "B B B \n"
        "B B B \n\n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n\n"
        "G G G \n"
        "G G G \n"
        "G G G \n\n";

    // Перенаправляем cout для проверки состояния после вращения против часовой стрелки
    std::ostringstream counterclockwiseOutput;
    std::cout.rdbuf(counterclockwiseOutput.rdbuf());
    cube.print();
    std::cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(counterclockwiseOutput.str(), expectedOutputAfterCounterclockwise);
}

TEST(CubeTest, FrontFaceMove_ClockwiseAndCounterclockwise) {
    Cube cube;

    // Заполняем куб с помощью FillingTheCube
    cube.FillingTheCube(cube);

    // Выполняем движение против часовой стрелки
    int selectTurn = 1;
    cube.FrontFaceMove(cube, selectTurn);

    // Ожидаемое состояние после вращения против часовой стрелки
    std::string expectedOutputAfterCounterclockwise =
        "B B B \n"
        "B B B \n"
        "R R R \n\n"
        "W W W   G R R   Y Y Y   O O B   \n"
        "W W W   G R R   Y Y Y   O O B   \n"
        "W W W   G R R   Y Y Y   O O B   \n\n"
        "O O O \n"
        "G G G \n"
        "G G G \n\n";

    // Перенаправляем cout для проверки состояния после вращения против часовой стрелки
    std::ostringstream counterclockwiseOutput;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(counterclockwiseOutput.rdbuf());
    cube.print();
    std::cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(counterclockwiseOutput.str(), expectedOutputAfterCounterclockwise);

    // Выполняем движение по часовой стрелке
    selectTurn = 2;
    cube.FrontFaceMove(cube, selectTurn);

    // Ожидаемое состояние после вращения по часовой стрелке (должно совпадать с состоянием после заполнения куба)
    std::string expectedOutputAfterClockwise =
        "B B B \n"
        "B B B \n"
        "B B B \n\n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n\n"
        "G G G \n"
        "G G G \n"
        "G G G \n\n";
    // Перенаправляем cout для проверки состояния после вращения по часовой стрелке
    std::ostringstream clockwiseOutput;
    std::cout.rdbuf(clockwiseOutput.rdbuf());
    cube.print();
    std::cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(clockwiseOutput.str(), expectedOutputAfterClockwise);
}

TEST(CubeTest, BackFaceMove_ClockwiseAndCounterclockwise) {
    Cube cube;

    // Заполняем куб с помощью FillingTheCube
    cube.FillingTheCube(cube);

    // Выполняем движение против часовой стрелки
    int selectTurn = 1;
    cube.BackFaceMove(cube, selectTurn);

    // Ожидаемое состояние после вращения против часовой стрелки
    std::string expectedOutputAfterCounterclockwise =
        "R R R \n"
        "B B B \n"
        "B B B \n\n"
        "W W W   R R G   Y Y Y   B O O   \n"
        "W W W   R R G   Y Y Y   B O O   \n"
        "W W W   R R G   Y Y Y   B O O   \n\n"
        "G G G \n"
        "G G G \n"
        "O O O \n\n";

    // Перенаправляем cout для проверки состояния после вращения против часовой стрелки
    std::ostringstream counterclockwiseOutput;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(counterclockwiseOutput.rdbuf());
    cube.print();
    std::cout.rdbuf(oldCoutBuffer);

    //std::cout << "Actual output after counterclockwise:\n" << counterclockwiseOutput.str(); // Отладочный вывод

    EXPECT_EQ(counterclockwiseOutput.str(), expectedOutputAfterCounterclockwise);

    // Выполняем движение по часовой стрелке
    selectTurn = 2;
    cube.BackFaceMove(cube, selectTurn);

    // Ожидаемое состояние после вращения по часовой стрелке
    std::string expectedOutputAfterClockwise =
        "B B B \n"
        "B B B \n"
        "B B B \n\n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n"
        "W W W   R R R   Y Y Y   O O O   \n\n"
        "G G G \n"
        "G G G \n"
        "G G G \n\n";

    // Перенаправляем cout для проверки состояния после вращения по часовой стрелке
    std::ostringstream clockwiseOutput;
    std::cout.rdbuf(clockwiseOutput.rdbuf());
    cube.print();
    std::cout.rdbuf(oldCoutBuffer);

    //std::cout << "Actual output after clockwise:\n" << clockwiseOutput.str(); // Отладочный вывод

    EXPECT_EQ(clockwiseOutput.str(), expectedOutputAfterClockwise);
}

TEST(CubeTest, RandomFilling_ValidMoves) {
    // Инициализируем куб
    Cube cube;
    cube.FillingTheCube(cube);

    // Сохраняем состояние куба перед случайными движениями
    Cube initialCubeState = cube; // Копируем текущее состояние

    // Перенаправляем cout в строковый поток для проверки вывода функции
    std::ostringstream output;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());

    // Вызовите RandomFilling
    cube.RandomFilling(cube);

    // Восстанавливаем оригинальный буфер вывода
    std::cout.rdbuf(oldCoutBuffer);

    // Проверяем, сколько элементов изменилось
    int changes = cube.countChanges(initialCubeState);

    // Ожидаем, что изменения произошли
    EXPECT_GT(changes, 0); // Проверяем, что было хотя бы одно изменение
}

// Тест для функции ReadCubeFromFile
TEST(CubeTest, ReadCubeFromFile_ValidFile) {
    // Создаем временный файл с состоянием куба
    std::string filename = "test_cube";
    std::ofstream file(filename + ".txt");
    ASSERT_TRUE(file.is_open());

    // Заполняем файл корректным состоянием куба
    file << "B B B \n"
        << "B B B \n"
        << "B B B \n\n"
        << "W W W\n"
        << "W W W\n"
        << "W W W\n\n"
        << "R R R\n"
        << "R R R\n"
        << "R R R\n\n"
        << "Y Y Y\n"
        << "Y Y Y\n"
        << "Y Y Y\n\n"
        << "O O O\n"
        << "O O O\n"
        << "O O O\n\n"
        << "G G G \n"
        << "G G G \n"
        << "G G G \n\n";
    file.close();

    // Инициализируем куб и читаем состояние из файла
    Cube cube;
    cube.ReadCubeFromFile(filename);

    // Проверяем, что состояние куба соответствует ожиданиям
    EXPECT_EQ(cube.getFace(0, 0, 0), 'W'); 
    EXPECT_EQ(cube.getFace(1, 0, 0), 'R');
    EXPECT_EQ(cube.getFace(2, 0, 0), 'Y');
    EXPECT_EQ(cube.getFace(3, 0, 0), 'O');
    EXPECT_EQ(cube.getFace(4, 0, 0), 'B');
    EXPECT_EQ(cube.getFace(5, 0, 0), 'G');

    // Удаляем временный файл
    std::remove((filename + ".txt").c_str());
}
