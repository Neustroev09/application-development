#ifndef BUFFER_H
#define BUFFER_H
#include <vector>
#include <list>
#include <iterator>

class EditorBuffer {
public:
    EditorBuffer();
    void insertCharacter(const char & letter); //вставка символов xxx в позиции курсора
    void deleteCharacter(); //удаление символа в позиции курсора
    void moveCursorForward(); //перемещение курсора на 1 символ вперёд
    void moveCursorBackward(); //перемещение курсора на 1 символ назад
    void moveCursorToStart(); //перемещение курсора в начало буфера
    void moveCursorToEnd(); //перемещение курсора в конец буфера
    void moveCursorUp(); //перемещение курсора на 1 строку вверх
    void moveCursorDown(); //перемещение курсора на 1 строку вниз
    void display(); //вывод содержимого буфера на экран
    ~EditorBuffer();

private:
    std::list<std::vector<char>> buffer;
    std::list<std::vector<char>> :: iterator line;
    int cursor_position = 0;
    int line_length = 100;

    void create_row();
    void hyphenation(const char & letter);
    bool check_current_row() const;
    bool check_next_row();
};
#endif // BUFFER_H
