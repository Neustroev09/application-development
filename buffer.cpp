#include "buffer.h"
#include <iostream>
#include <string>
#include <vector>

EditorBuffer::EditorBuffer()
{
    std::vector<char> cell;
    buffer.push_back(cell);
    line =  buffer.begin();
}

void EditorBuffer::create_row()
{
    std::vector<char> cell;
    buffer.push_back(cell);
    line++;
}

void EditorBuffer::hyphenation(const char & letter)
{
    if (cursor_position < line_length) {
        line->pop_back();
        line->insert(line->begin() + cursor_position, letter);
        cursor_position++;
    } else {
        cursor_position = 0;
    }
}

bool EditorBuffer::check_current_row() const
{
    if (line->size() < line_length) {
        return true;
    } else {
        return false;
    }
}

bool EditorBuffer::check_next_row()
{
    line++;
    bool p = check_current_row();
    line--;
    return p;
}

void EditorBuffer::insertCharacter(const char & letter)
{
    //вставка в конец
    if  (cursor_position == line->size() && line == --buffer.end()) {
        //строка не заполнена
        if (check_current_row()) {
            line->push_back(letter);
            cursor_position++;

        }
        //строка заполнена
        else {
            create_row();
            cursor_position = 0;
            line->push_back(letter);
            cursor_position++;
        }
    }
    //вставка не в конец
    else {
        //текущая строка не заполнена
        if (check_current_row()) {
            line->insert(line->begin() + cursor_position, letter);
            cursor_position++;
        }
        //текущая строка заполнена, значит проверим следующую
        else {
            if (check_next_row()) {
                //следующая строка свободна, значит переносим в нее символы
                char p = line->back();
                hyphenation(letter);

                if (cursor_position != 0) {
                    line++;
                    line->insert(line->begin(), p);
                    line--;
                } else {
                    line++;
                    line->insert(line->begin(), letter);
                    cursor_position++;
                }
            } else {
                //следующая строка занята, значит создаем новую и переносим в нее
                char p = line->back();
                hyphenation(letter);
                std::vector<char> cell;
                line++;

                if (cursor_position != 0) {
                    cell.push_back(p);
                    buffer.insert(line, cell);
                    line--;
                    line--;//
                } else {
                    cell.push_back(letter);
                    cursor_position++;
                    buffer.insert(line, cell);
                    line--;
                }
            }
        }
    }
}

void EditorBuffer::deleteCharacter()
{
    //удаление из начала строки
    if (line != buffer.begin() && cursor_position == 0) {
        line--;
        line->pop_back();
        cursor_position = line->size();
        return;
    }
    //удаление из произвольного места
    if (cursor_position != 0) {
        line->erase(line->begin()+cursor_position-1);
        cursor_position--;
    }
}

void EditorBuffer::moveCursorForward()
{
    //когда курсор в конце строки
    if (cursor_position == line->size() && line != --buffer.end()) {
        line++;
        cursor_position = 0;
        return;
    }
    //когда курсор в произвольном месте
    if (cursor_position != line->size()){
        cursor_position++;
    }
}

void EditorBuffer::moveCursorBackward()
{
    //когда курсор в начале строки
    if (line != buffer.begin() && cursor_position == 0) {
        line--;
        cursor_position = line->size();
        return;
    }
    //когда курсор в произвольном месте
    if (cursor_position != 0){
        cursor_position--;
    }
}

void EditorBuffer::moveCursorToStart()
{
    line = buffer.begin();
    cursor_position = 0;
}

void EditorBuffer::moveCursorToEnd()
{
    line = --buffer.end();
    cursor_position = line->size();
}

void EditorBuffer::moveCursorUp()
{
    if (line != buffer.begin()) {
        int count = 0;
        while (count <= line_length) {
            moveCursorBackward();
            count++;
        }
    }
}

void EditorBuffer::moveCursorDown()
{
    if (line != --buffer.end()) {
        int count = 0;
        while (count <= line_length) {
            moveCursorForward();
            count++;
        }
    }
}

void EditorBuffer::display()
{
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    int count = 0;
    for (std::list<std::vector<char>> :: iterator it = buffer.begin(); it != buffer.end(); ++it) {
        for (std::vector<char> :: iterator it1 = it->begin(); it1 != it->end(); ++it1) {
            if (count == line_length) {std::cout << '\n'; count = 0;}
            std::cout << *it1;
            if (it == line && (it1 == (it->begin() + cursor_position - 1))) std::cout << '|';
            count++;
        }
    }
    std::cout << std::endl;
}

EditorBuffer::~EditorBuffer()
{

}
