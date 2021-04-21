#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, a, b, s, s2, s3, kol, start;
    vector<pair<int, int>> mn1;
    vector<pair<int, int>> mn2;
    vector<pair<int, int>> ob;
    vector<pair<int, int>> per;
    vector<pair<int, int>> raz1;
    vector<pair<int, int>> raz2;
    vector<pair<int, int>> simraz;
    vector<pair<int, int>> inv1;
    vector<pair<int, int>> inv2;
    vector<pair<int, int>> komp;
    cout << '\t' << "Vvedite moschnost grafika A, ne prevoshodyashyu 20: " << endl;
    cin >> n; //вводится мощность А

    cout << "Vvedite elementi grafika A v predelah [-1;50]: " << endl;
    for (int i = 0; i < n; i++) //происходит ввод первого и второго элемента каждого кортежа
    {
        cin >> a;
        cin >> b;
        mn1.push_back(make_pair(a, b));
    }


    cout << '\t' << "Vvedite moschnost grafika B, ne prevoshodyashuyu 20: " << endl;
    cin >> m; //вводится мощность В

    cout << "Vvedite elementi grafika B v predelah [-1;50]: " << endl;
    for (int i = 0; i < m; i++) //происходит ввод первого и второго элемента каждого кортежа
    {
        cin >> a;
        cin >> b;
        mn2.push_back(make_pair(a, b));
    }

    while (true)
    {
        cout << '\t' << "Viberite deistvie:" << endl;
        cout << '\t' << "1 - obedinenie" << '\n' << '\t' << "2 - peresechenie;" << '\n' << '\t' << "3 - rasnost;" << '\n' << '\t' << "4 - simmetricheskaya raznost;" << '\n' << '\t' << "5 - inversia;" << '\n' << '\t' << "6 - kompozicia;" << '\n' << '\t' << "0 - exit." << endl;
        cin >> s; //выбор желаемой операции
        switch (s)
        {
        case 1: //объединение
            for (int i = 0; i < n; i++) { //для каждого кортежа 1-го графика
                kol = 1; //локальная переменная
                for (int j = 0; j < m; j++) { //для каждого кортежа 2-го графика
                    if (mn1[i] == mn2[j]) //если кортеж в 1ом графике равен кортежу во втором
                        kol++; //увеличиваем локальную переменную
                }
                if (kol == 1) //если локальная переменная для n-ого кортежа 1-го графика =1, т.е. не повторяется во 2-ом графике записываем его в график объединения
                    ob.push_back(mn1[i]);
            }
            for (int i = 0; i < m; i++) { //записываем в график объединения весь 2-ой график
                ob.push_back(mn2[i]);
            }
            cout << '\t' << "Obedinenie= ( "; //вывод на экран
            for (unsigned int k = 0; k < ob.size(); k++) {
                if (k < ob.size() - 1)
                    cout << "< " << ob[k].first << ", " << ob[k].second << ">, ";
                else
                    cout << "< " << ob[k].first << ", " << ob[k].second << "> )" << '\n' << endl;

            }
            break;
        case 2: //пересечение
            for (int i = 0; i < n; i++) { //для каждого кортежа 1-го графика
                kol = 1;  //локальная переменная
                for (int j = 0; j < m; j++) { //для каждого кортежа 2-го графика
                    if (mn1[i] == mn2[j]) //если кортеж в 1ом графике равен кортежу во втором
                        kol++;//увеличиваем локальную переменную
                }
                if (kol != 1) //если локальная переменная для n-ого кортежа 1-го графика !=1, т.е. повторяется во 2-ом графике записываем его в график пересечения
                    per.push_back(mn1[i]);
            }
            cout << '\t' << "Peresechenie= ( "; //вывод
            for (unsigned int k = 0; k < per.size(); k++) {
                if (k < per.size() - 1)
                    cout << "< " << per[k].first << ", " << per[k].second << ">, ";
                else
                    cout << "< " << per[k].first << ", " << per[k].second << "> )" << '\n' << endl;

            }
            break;
        case 3: //разность
            cout << '\t' << "Viberite deistvie:" << endl;
            cout << '\t' << "1 - A-B;" << '\n' << '\t' << "2 - B-A;" << '\n' << '\t' << "0 - exit." << endl;
            cin >> s2; //выбор вида разницы
            switch (s2)
            {
            case 1: //А-В
                for (int i = 0; i < n; i++) { //для каждого кортежа 1-го графика
                    kol = 1; //локальная переменная
                    for (int j = 0; j < m; j++) { //для каждого кортежа 2-го графика
                        if (mn1[i] == mn2[j]) //если кортеж в 1ом графике равен кортежу во втором
                            kol++;//увеличиваем локальную переменную
                    }
                    if (kol == 1) //если локальная переменная для n-ого кортежа 1-го графика =1, т.е. не повторяется во 2-ом графике записываем его в график разности
                        raz1.push_back(mn1[i]);
                }
                cout << '\t' << "Raznost A-B= ( "; //вывод
                for (unsigned int k = 0; k < raz1.size(); k++) {
                    if (k < raz1.size() - 1)
                        cout << "< " << raz1[k].first << ", " << raz1[k].second << ">, ";
                    else
                        cout << "< " << raz1[k].first << ", " << raz1[k].second << "> )" << '\n' << endl;
                }
                break;
            case 2: //В-А
                for (int i = 0; i < m; i++) { //для каждого кортежа 2-го графика
                    kol = 1; //локальная переменная
                    for (int j = 0; j < n; j++) { //для каждого кортежа 1-го графика
                        if (mn2[i] == mn1[j]) //если кортеж во 2-ом графике равен кортежу в 1-ом
                            kol++;//увеличиваем локальную переменную
                    }
                    if (kol == 1)//если локальная переменная для n-ого кортежа 2-го графика =1, т.е. не повторяется в 1-ом графике записываем его в график разности
                        raz2.push_back(mn2[i]);
                }
                cout << '\t' << "Raznost B-A= ( "; //вывод
                for (unsigned int k = 0; k < raz2.size(); k++) {
                    if (k < raz2.size() - 1)
                        cout << "< " << raz2[k].first << ", " << raz2[k].second << ">, ";
                    else
                        cout << "< " << raz2[k].first << ", " << raz2[k].second << "> )" << '\n' << endl;
                }
                break;
            case 0: //выход
                break;
            }
            break;
        case 4: //симметрическая разность
            for (int i = 0; i < n; i++) { //для каждого кортежа 1-го графика
                kol = 1; //локальная переменная
                for (int j = 0; j < m; j++) { //для каждого кортежа 2-го графика
                    if (mn1[i] == mn2[j]) //если кортеж в 1ом графике равен кортежу во втором
                        kol++;//увеличиваем локальную переменную
                }
                if (kol == 1) //если локальная переменная для n-ого кортежа 1-го графика =1, т.е. не повторяется во 2-ом графике записываем его в график симметричной разности
                    simraz.push_back(mn1[i]);
            }
            for (int i = 0; i < m; i++) { //для каждого кортежа 2-го графика
                kol = 1; //локальная переменная
                for (int j = 0; j < n; j++) { //для каждого кортежа 1-го графика
                    if (mn2[i] == mn1[j]) //если кортеж во 2-ом графике равен кортежу в 1-ом
                        kol++;//увеличиваем локальную переменную
                }
                if (kol == 1)//если локальная переменная для n-ого кортежа 2-го графика =1, т.е. не повторяется в 1-ом графике записываем его в график симметричной разности
                    simraz.push_back(mn2[i]);
            }
            cout << '\t' << "Simmetricheskaya raznost= ( "; //вывод
            for (unsigned int k = 0; k < simraz.size(); k++) {
                if (k < simraz.size() - 1)
                    cout << "< " << simraz[k].first << ", " << simraz[k].second << ">, ";
                else
                    cout << "< " << simraz[k].first << ", " << simraz[k].second << "> )" << '\n' << endl;
            }
            break;
        case 5: //инверсия
            cout << '\t' << "Viberite deistvie:" << endl;
            cout << '\t' << "1 - inversia A;" << '\n' << '\t' << "2 - inversia B;" << '\n' << '\t' << "0 - exit." << endl;
            cin >> s3; //выбор вида инверсии
            switch (s3)
            {
            case 1: //инверсия А
                for (int i = 0; i < n; i++) //копирование изначального графика в вектор для хранения инверсии
                {
                    inv1.push_back(mn1[i]);
                }
                for (unsigned int k = 0; k < inv1.size(); k++) //для каждого кортежа меняем 1ый элемент и 2ой
                {
                    swap(inv1[k].first, inv1[k].second);
                }
                cout << '\t' << "Inversia A= ( "; //вывод
                for (unsigned int k = 0; k < inv1.size(); k++) {
                    if (k < inv1.size() - 1)
                        cout << "< " << inv1[k].first << ", " << inv1[k].second << ">, ";
                    else
                        cout << "< " << inv1[k].first << ", " << inv1[k].second << "> )" << '\n' << endl;
                }
                break;
            case 2: //инверсия В
                for (int i = 0; i < m; i++) //копирование изначального графика в вектор для хранения инверсии
                {
                    inv2.push_back(mn2[i]);
                }

                for (unsigned int k = 0; k < inv2.size(); k++) //для каждого кортежа меняем 1ый элемент и 2ой
                {
                    swap(inv2[k].first, inv2[k].second);
                }
                cout << '\t' << "Inversia B= ( "; //вывод
                for (unsigned int k = 0; k < inv2.size(); k++) {
                    if (k < inv2.size() - 1)
                        cout << "< " << inv2[k].first << ", " << inv2[k].second << ">, ";
                    else
                        cout << "< " << inv2[k].first << ", " << inv2[k].second << "> )" << '\n' << endl;
                }
                break;
            case 0: //выход
                break;
            }
            break;
        case 6: //композиция
            start = 0;
            for (int i = 0; i < n; i++) { //для каждого кортежа 1-го графика
                while (start < m) //для каждого кортежа 2-го графика
                {
                    if (mn1[i].second == mn2[start].first) //если второй элемент кортежа из А равен первому элементу кортежа из В
                    {
                        komp.push_back(make_pair(mn1[i].first, mn2[start].second)); //записываем в график композиции кортеж, состоящий из 1-го элемента выбранного кортежа А и 2-го элемента выбранного кортежа В
                    }
                    start++; //берем следующий кортеж из В
                }
                start = 0; // каждый раз начинаем с начала графика В
            }
            cout << '\t' << "Kompozicia= ( "; //вывод
            for (unsigned int k = 0; k < komp.size(); k++) {
                if (k < komp.size() - 1)
                    cout << "< " << komp[k].first << ", " << komp[k].second << ">, ";
                else
                    cout << "< " << komp[k].first << ", " << komp[k].second << "> )" << '\n' << endl;
            }
            break;
        case 0: //выход
            exit(1);
        }
    }
}
