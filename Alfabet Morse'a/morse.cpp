///------------------------------------------------------------------------------------------------------/
//Program przekszta³ca ³añcuchy znakowe na alfabet Morse'a odtwarzane na g³oœniku 
//
//Autor: Jakub Lefik
//Data utworzenia: 20.11.2020r.
//Version: 1.0
///------------------------------------------------------------------------------------------------------/

#include "morse.h"

//--------------------------------------------------4 IRON RULES---------------------------------------------------------------

morse::morse()
{
    frequency = 0;
    dotTime = 0;
    dashTime = 0;
    pausa = 0;
    charPause = 0;
}

morse::morse(const morse& Kop)
{
    frequency = Kop.frequency;
    dotTime = Kop.dotTime;
    dashTime = Kop.dashTime;
    pausa = Kop.pausa;
    charPause = Kop.charPause;
}

morse& morse::operator=(const morse& Prz) {
    this->frequency = Prz.frequency;
    this->dotTime = Prz.dotTime;
    this->dashTime = Prz.dashTime;
    this->pausa = Prz.pausa;
    this->charPause = Prz.charPause;

    return *this;
}

morse::~morse()
{
}

//-------------------------------------------------Gety & Sety------------------------------------------------------------------------

void morse::setFrequency(unsigned int x)
{
    frequency = x;
}

void morse::setDotTime(unsigned int y)
{
    dotTime = y;
}

void morse::setDashTime(unsigned int z)
{
    dashTime = z;
}

void morse::setPause(unsigned int w)
{
    pausa = w;
}

void morse::setCharPause(unsigned int c)
{
    charPause = c;
}

unsigned int morse::getFrequency()
{
    return this->frequency;
}

unsigned int morse::getDotTime()
{
    return this->dotTime;
}

unsigned int morse::getDashTime()
{
    return this->dashTime;
}

unsigned int morse::getPause()
{
    return this->pausa;
}

unsigned int morse::getCharPause()
{
    return this->charPause;
}

//--------------------------------------------------------Przeci¹¿enia <<-----------------------------------------------------------------

morse& operator<<(morse& ml, long l)
{
    std::stringstream sent;
    sent << l;
    std::string Stronk;
    Stronk = sent.str();
    sent.str("");
    Stronk = ml.translator(Stronk);
    for (int i = 0; i < Stronk.length(); i++)
    {
        if (Stronk[i] == '-')
        {
            Beep(ml.frequency, ml.dashTime);
            Sleep(ml.pausa);
        }
        else if (Stronk[i] == '.')
        {
            Beep(ml.frequency, ml.dotTime);
            Sleep(ml.pausa);
        }
        else if (Stronk[i] == ' ')
        {
            Sleep(ml.charPause);
        }
    }
    return ml;
}

morse& operator<<(morse& md, double d)
{
    std::stringstream sent;
    sent << d;
    std::string Stronk;
    Stronk = sent.str();
    sent.str("");
    Stronk = md.translator(Stronk);
    for (int i = 0; i < Stronk.length(); i++)
    {
        if (Stronk[i] == '-')
        {
            Beep(md.frequency, md.dashTime);
            Sleep(md.pausa);
        }
        else if (Stronk[i] == '.')
        {
            Beep(md.frequency, md.dotTime);
            Sleep(md.pausa);
        }
        else if (Stronk[i] == ' ')
        {
            Sleep(md.charPause);
        }
    }
    return md;
}

    morse& operator<<(morse & mt, std::string text)
    {
        std::stringstream sent;
        sent << text;
        std::string Stronk;
        Stronk = sent.str();
        sent.str("");
        Stronk = mt.translator(Stronk);
        for (int i = 0; i < Stronk.length(); i++)
        {
            if (Stronk[i] == '-')
            {
                Beep(mt.frequency, mt.dashTime);
                Sleep(mt.pausa);
            }
            else if (Stronk[i] == '.')
            {
                Beep(mt.frequency, mt.dotTime);
                Sleep(mt.pausa);
            }
            else if (Stronk[i] == ' ')
            {
                Sleep(mt.charPause);
            }
        }
        return mt;
    }

    //------------------------------------------------------Metoda t³umacz¹ca-----------------------------------------------------------------------

    std::string morse::translator(std::string abcd) {
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

                //Cyfry--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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

            default:  break;
            }
        }
        return sent;
    }

    morse& pause(morse& manip)	//funkcja pause okreslajaca zachowanie manipulatora
     {
        Sleep(manip.charPause);
        return manip;
     }

    morse& morse::operator<<(morse& (*mptr)(morse&)) 
    {                                                   
        return(*mptr)(*this);
    }


        
        