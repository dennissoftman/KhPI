#ifndef DELTATIME_HPP
#define DELTATIME_HPP

#include <string>

/*
Создать класс Время (часы, минуты, секунды).
– Класс должен содержать гетеры и сеттеры
(методы изменения времени на заданное количество часов, минут и секунд и вывода значений каждого поля)
с проверкой допустимости вводимых значений. В случае недопустимых значений полей – корректно обработать ситуацию.
– Создать функцию вывода всего объекта время на экран.
– Создать функцию подсчета разности времен двух объектов.
– Создать функцию сравнения времен двух объектов.
– Определить угол между часовой и минутной стрелками.
    1 hour   = 360 / 12 = 30*
    1 minute = 360 / 60 = 6*
*/

class DeltaTime
{
public:
    DeltaTime();

    void SetHours(int h);
    void SetMinutes(int m);
    void SetSeconds(int s);

    std::string GetTime() const;
    float GetAngle() const; // angle between hour and minute arrows

    DeltaTime operator -(const DeltaTime &other) const;
    bool operator >(const DeltaTime &other) const;
    bool operator >=(const DeltaTime &other) const;
    bool operator <(const DeltaTime &other) const;
    bool operator <=(const DeltaTime &other) const;
    bool operator ==(const DeltaTime &other) const;

private:
    uint32_t d_time;
};

#endif // DELTATIME_HPP
