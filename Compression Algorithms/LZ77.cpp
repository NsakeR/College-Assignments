// NIE SKOŃCZONE!!!

#include <iostream>
#include <vector>

using namespace std;

vector<pair<unsigned int, unsigned int>> findStr(string dic, string buff) {
    string temp;
    vector<pair<unsigned int, unsigned int>> vec;

    for (size_t i = 0; i < buff.length(); i++) {
        temp += buff[i];
        
        if (dic.find(temp[0]) > 20000) {

           // cout <<"Nie ma takiego ciagu! " << temp[0] << endl;
            vec.push_back(make_pair(0, 1));
            return vec;
        }
        if (dic.find(temp) > 20000 && temp.length() != 0) {
            temp.erase(temp.length() - 1);
            vec.push_back(make_pair(dic.find(temp), temp.length()));
            return vec;
        }
    }
}

void moveString(string &dic, string &buff, string mess, int howMany, int pos) {
    
    dic.erase(0, howMany);
    for (int i = 0; i < howMany; i++) {
        dic += buff[i];
    }

    buff.erase(0, howMany);
    for (int i = 0; i < howMany; i++) {
        if (pos + i + 1 <= mess.length())
            buff += mess[pos + i + 1];
        else
            break;
    }
}


int main()
{
    string buff, dict, mess;
    int lenOfDic = 0, lenOfBuf = 0;

    cout << "Kodowanie LZ77 \n";
    cout << "Podaj dlugosc slownika i buforu \n";
    cout << "Slownik: "; cin >> lenOfDic;
    cout << "Bufor: "; cin >> lenOfBuf;

    cout << "Podaj komunikat: "; cin >> mess;

    cout << endl;// << "Bufor: ";
    for (int i = 0; i < lenOfBuf; i++) {
        buff += mess[i];
        //cout << buff[i];
    }
    //cout << endl << "Slownik: ";
    for (int i = 0; i < lenOfDic; i++) {
        dict += buff[0];
        //cout << dict[i];
    }
    
    cout << endl << dict[0] << endl;
    dict.erase(0, 1);
    dict += buff[0];
    buff.erase(0, 1);
    buff += mess[lenOfBuf];

    //cout << endl << "Slownik: ";
    //for (int j = 0; j < dict.length(); j++) {
    //    cout << dict[j];
    //}
    //cout << endl << "Bufor: ";
    //for (int j = 0; j < dict.length(); j++) {
    //    cout << buff[j];
    //}

    int count = lenOfBuf;
    for (int i = 0; i < mess.length(); i++) {
        auto t = findStr(dict, buff);
        cout << t[0].first << t[0].second << buff[t[0].second] << endl;
        
        //for (int j = 0; j < mess.length(); j++) {
        //    cout << mess[j];
        //}

        moveString(dict, buff, mess, t[0].second, count);
        cout << endl <<"Slownik: "; 
        for (int j = 0; j < dict.length(); j++) {
            cout << dict[j];
        }
        cout << endl << "Bufor: ";
        for (int j = 0; j < dict.length(); j++) {
            cout << buff[j];
        }
        

        count += t[0].second + 1;
        t.clear();
    }

    return 0;
}
