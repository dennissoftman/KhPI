#ifndef TRAIN_HPP
#define TRAIN_HPP

/*
Создайте класс с именем Train, содержащую поля:
    - название пункта назначения
    - номер поезда,
    - время отправления
Ввести данные в массив из пяти элементов типа Train, упорядочить элементы
по номерам поездов. Добавить возможность вывода информации о поезде, номер которого введен
пользователем. Добавить возможность сортировки массив по пункту назначения, причем поезда
с одинаковыми пунктами назначения должны быть упорядочены по времени отправления.
*/

#include <string>

//struct hm_s
//{
//    unsigned minutes:6;
//    unsigned hours:5;
//} typedef hm_t;
typedef uint16_t hm_t;

class Train
{
public:
    Train();
    Train(const std::string &_dest, int _t_id, hm_t _d_time);

    void SetDest(const std::string &_dest);
    void SetTID(int _t_id);
    void SetDT(hm_t _d_time);

    const std::string &GetDest() const;
    int GetTID() const;
    hm_t GetDT() const;

    std::string GetInfo() const;
private:
    std::string dest;
    int t_id;
    hm_t d_time;
};

#endif // TRAIN_HPP
