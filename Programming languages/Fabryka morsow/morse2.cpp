//----------------------------------------------------------------------------------------------------------------------------------
// Plik .cpp klasy bazowej morse2. Zawiera definicje translatorów.
//
//
// Wersja: 1.0		Autor: Jakub Lefik		
// Data: 23.01.2021
//
// Historia zmian: 
//----------------------------------------------------------------------------------------------------------------------------------

#include "morse2.h"

std::string morse2::translator_s(std::string abcd) {
    std::string sent;
    // T³umaczenie Morse'a z https://gist.github.com/DawiDeX-Zero/c39981e4659f71e59324a0214b1e44d9
    for (int i = 0; i < abcd.length(); i++) {
        switch (abcd[i]) {
        case 'a': case 'A':
            sent += ".-"; break;
        case 'b': case 'B':
            sent += "-..."; break;
        case 'c': case 'C':
            sent += "-.-."; break;
        case 'd': case 'D':
            sent += "-.."; break;
        case 'e': case 'E':
            sent += "."; break;
        case 'f': case 'F':
            sent += "..-."; break;
        case 'g': case 'G':
            sent += "--."; break;
        case 'h': case 'H':
            sent += "...."; break;
        case 'i': case 'I':
            sent += ".."; break;
        case 'j': case 'J':
            sent += ".---"; break;
        case 'k': case 'K':
            sent += "-.-"; break;
        case 'l': case 'L':
            sent += ".-.."; break;
        case 'm': case 'M':
            sent += "--"; break;
        case 'n': case 'N':
            sent += "-."; break;
        case 'o': case 'O':
            sent += "---"; break;
        case 'p': case 'P':
            sent += ".--."; break;
        case 'q': case 'Q':
            sent += "--.-"; break;
        case 'r': case 'R':
            sent += ".-."; break;
        case 's': case 'S':
            sent += "..."; break;
        case 't': case 'T':
            sent += "-"; break;
        case 'u': case 'U':
            sent += "..-"; break;
        case 'v': case 'V':
            sent += "...-"; break;
        case 'w': case 'W':
            sent += ".--"; break;
        case 'x': case 'X':
            sent += "-..-"; break;
        case 'y': case 'Y':
            sent += "-.--"; break;
        case 'z': case 'Z':
            sent += "--.."; break;

            //Polskie znaki------------------------------------------------------------------------------------------------------------------------------------------------------------------
        case '¹': case '¥':
            sent += ".-.-"; break;
        case 'æ': case 'Æ':
            sent += "-.-.."; break;
        case 'ê': case 'Ê':
            sent += "..-.."; break;
        case '³': case '£':
            sent += ".-..-"; break;
        case 'ñ': case 'Ñ':
            sent += "--.--"; break;
        case 'ó': case 'Ó':
            sent += "---."; break;
        case 'œ': case 'Œ':
            sent += "...-..."; break;
        case '¿': case '¯':
            sent += "--..-."; break;
        case 'Ÿ': case '':
            sent += "--..-"; break;
 
        case '1':
            sent += ".----"; break;
        case '2':
            sent += "..---"; break;
        case '3':
            sent += "...--"; break;
        case '4':
            sent += "....-"; break;
        case '5':
            sent += "....."; break;
        case '6':
            sent += "-...."; break;
        case '7':
            sent += "--..."; break;
        case '8':
            sent += "---.."; break;
        case '9':
            sent += "----."; break;
        case '0':
            sent += "-----"; break;

        case ' ':
            sent += " "; break;
        case '.':
            sent += ".-.-.-"; break;

        default:  break;
        }
    }
    return sent;
}

std::string morse2::translator_i(int integer_number)
{
    std::string sent;
    std::string temp_s_i = std::to_string(integer_number);
    for (int i = 0; i < temp_s_i.length(); i++) {
        switch(temp_s_i[i]){
           case '1':
               sent += ".----"; break;
           case '2':
               sent += "..---"; break;
           case '3':
               sent += "...--"; break;
           case '4':
               sent += "....-"; break;
           case '5':
               sent += "....."; break;
           case '6':
               sent += "-...."; break;
           case '7':
               sent += "--..."; break;
           case '8':
               sent += "---.."; break;
           case '9':
               sent += "----."; break;
           case '0':
               sent += "-----"; break;

           default:  break;
           }
        }
        return sent;
    }

std::string morse2::translator_d(double double_number)
{
    std::string sent;
    std::string temp_s_d = std::to_string(double_number);
    for (int i = 0; i < temp_s_d.length(); i++) {
        switch (temp_s_d[i]) {
        case '1':
            sent += ".----"; break;
        case '2':
            sent += "..---"; break;
        case '3':
            sent += "...--"; break;
        case '4':
            sent += "....-"; break;
        case '5':
            sent += "....."; break;
        case '6':
            sent += "-...."; break;
        case '7':
            sent += "--..."; break;
        case '8':
            sent += "---.."; break;
        case '9':
            sent += "----."; break;
        case '0':
            sent += "-----"; break;

        case '.':
            sent += ".-.-.-"; break;

        default:  break;
        }
    }
    return sent;
}


std::string morse2::translator_f(float float_number)
{
    std::string sent;
    std::string temp_s_f = std::to_string(float_number);
    for (int i = 0; i < temp_s_f.length(); i++) {
        switch (temp_s_f[i]) {
        case '1':
            sent += ".----"; break;
        case '2':
            sent += "..---"; break;
        case '3':
            sent += "...--"; break;
        case '4':
            sent += "....-"; break;
        case '5':
            sent += "....."; break;
        case '6':
            sent += "-...."; break;
        case '7':
            sent += "--..."; break;
        case '8':
            sent += "---.."; break;
        case '9':
            sent += "----."; break;
        case '0':
            sent += "-----"; break;

        case '.':
            sent += ".-.-.-"; break;

        default:  break;
        }
    }
    return sent;
}

