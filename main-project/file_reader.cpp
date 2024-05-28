#include "file_reader.h"
#include <fstream>
#include <cstring>
#include <iostream>

Date convert_to_date(char* str)
{
    Date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

Time convert_to_time(char* str)
{
    Time result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hours = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.minuts = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.seconds = atoi(str_number);
    return result;
}



void read(const char* file_name, tell_subscribe* array[], int& size) {
        std::ifstream file(file_name);
        if (file.is_open())
        {
            size = 0;
            char tmp_buffer[MAX_NUMBER_SIZE];
            while (!file.eof())
            {
                tell_subscribe* item = new tell_subscribe;
                file >> item->number;
                file >> tmp_buffer;
                item->date = convert_to_date(tmp_buffer);
                file >> tmp_buffer;
                item->time_start = convert_to_time(tmp_buffer);
                file >> tmp_buffer;
                item->time_duration = convert_to_time(tmp_buffer);
                file >> tmp_buffer;
                if (!strcmp(tmp_buffer,"город"))
                    item->tarif = Tarifs::город;
                else if (!strcmp(tmp_buffer, "межгород"))
                    item->tarif = Tarifs::межгород;
                else if (!strcmp(tmp_buffer, "международный"))
                    item->tarif = Tarifs::международный;
                else if (!strcmp(tmp_buffer, "мобильный"))
                    item->tarif = Tarifs::мобильный;
                file >> item->cost;
                array[size++] = item;
            }
            file.close();
        }
        else
        {
            throw "Ошибка открытия файла";
        }
}