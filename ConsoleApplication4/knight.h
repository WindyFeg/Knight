#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;

const int BOWSER_GIVE_UP = 0;
const int MADBEAR = 1;
const int BANDIT = 2;
const int LORDLUPIN = 3;
const int ELF_MONSTER = 4;
const int TROLL = 5;
const int SHAMAN_TWICH = 6;
const int SIREN_VAJSH = 7;
const int EXCALIBUR_SWORD = 8;
const int MYTHIRL_AMMOR = 9;
const int EXCALIPOOR_BAD_SWORD = 10;
const int MUSH_MARIO = 11;
const int MUSH_FIB = 12;
const int MUSH_GHOST = 13;
const int MUSH_KNIGHT = 14;
const int REMEDY_POSION = 15;
const int PHOENIX_DOWN = 16;
const int MERLIN_50 = 17;
const int NINA_THE_RING = 18;
const int ABYSS = 19;
const int TIME_GATE = 20;
const int GUINEVERE = 21;
const int LIGHT_WING = 22;
const int ODIN = 23;
const int DRAGON_SWORD = 24;
const int MEET_BOWSER = 99;
const int EVENT_SIZE = 1000;
const int MAX_CHARACTER_EACH_LINE = 250;


struct knight
{
    int HP;
    int DF;
    int level;
    int remedy;
    int gold;
    int phoenixdown;
};

// read data from input file to corresponding variables
// return 1 if successfully done, otherwise return 0
void Check_DF_HP_Gold_level(int& HP, int& DF, int& gold, int& lev, int maxhp)
{
    if (HP > maxhp) { HP = maxhp; };
    if (DF > 20) { DF = 20; };
    if (gold > 500) { gold = 500; };
    if (lev > 10) { lev = 10; };
}

int LevelEnimy(int i)
{
    int b = i % 10;
    int levelO = i > 6 ? (b > 5 ? b : 5) : b;
    return levelO;
}

void Check_HP(int& HP, int& phenix, int maxhp, bool& you_die, bool& timegate, int& i, int& j, bool& frog, bool& tiny)
{
    if (HP < 0 && phenix == 0) { you_die = true; }
    else if (HP < 0 && phenix != 0)
    {
        phenix--;
        HP = maxhp;
        if (timegate) { i = j; timegate = false; };
        frog = false; tiny = false;
    }

}

void Tiny_trans(int& HP)
{
    if (HP >= 5) { HP /= 5; }
    else { HP = 1; }
}

void Frog_trans(int& Level)
{
    Level = 1;
}

void Back_to_normal_size(int& HP, int& maxhp)
{
    HP = HP * 5;
    if (HP > maxhp) { HP = maxhp; }
}

void Use_Medicine_Remedy(int& remedy, int& HP, bool& tiny_frog, int& maxhp)
{
    if (remedy > 0) { remedy--; HP *= 5; tiny_frog = false; }
    if (HP > maxhp) { HP = maxhp; }
}
void Use_Medicine_Remedy1(int& remedy, int& LE, bool& tiny_frog, int& lecu)
{
    if (remedy > 0) { remedy--; LE = lecu; }
    tiny_frog = false;
}

void Back_to_level(int& level, int& levelbase)
{
    level = levelbase;
}
void HP_DF_Mushghost(int& HP, int& DF)
{
    if (HP < 51) { HP = 1; }
    else { HP -= 50; }
    if (DF < 6) { DF = 1; }
    else { DF -= 5; }
}

void HP_fibonacy(int& HP)
{
    int Fib[100], i = 1;
    Fib[0] = 1; Fib[1] = 1;
    do
    {
        i++;
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    } while (Fib[i] < HP);
    HP += Fib[i - 1];
}

bool Check_friendly_num(int HP, int Gold)
{
    double abudancy1, abudancy2;
    double divisor1 = 0, divisor2 = 0;
    for (int i = 1; i <= HP; i++) { if (HP % i == 0) { divisor1 += i; }; };
    for (int i = 1; i <= Gold; i++) { if (Gold % i == 0) { divisor2 += i; }; };
    abudancy1 = divisor1 / HP;
    abudancy2 = divisor2 / Gold;
    if (abudancy1 == abudancy2) { return true; }
    else return false;
}

void int2string(int n, string& result)
{
    if (n == 1) { result = result + '1'; }
    else if (n == 2) { result = result + '2'; }
    else if (n == 3) { result = result + '3'; }
    else if (n == 4) { result = result + '4'; }
    else if (n == 5) { result = result + '5'; }
    else if (n == 6) { result = result + '6'; }
    else if (n == 7) { result = result + '7'; }
    else if (n == 8) { result = result + '8'; }
    else if (n == 9) { result = result + '9'; }
    else if (n == 0) { result = result + '0'; };
}

void Threenum(int& so, string& result, int a)
{
    so = a / 100;
    int2string(so, result);
    so = a % 100;
    so = so / 10;
    int2string(so, result);
    so = a % 100;
    so = a % 10;
    int2string(so, result);
}
void Twonum(int& so, string& result, int a)
{
    so = a / 10;
    int2string(so, result);
    so = a % 10;
    int2string(so, result);
}

void Num(int& so, string& result, int a)
{
    so = a;
    int2string(so, result);
}

int Giai_mat_ma(int arr[], knight& the_knight, int nEvent)
{
    int so, tong = 0; string result;
    if (the_knight.HP >= 100)
    {
        Threenum(so, result, the_knight.HP);
    }
    else if (the_knight.HP >= 10)
    {
        Twonum(so, result, the_knight.HP);
    }
    else if (the_knight.HP < 10)
    {
        Num(so, result, the_knight.HP);
    }
    if (the_knight.DF >= 10)
    {
        Twonum(so, result, the_knight.DF);
    }
    else if (the_knight.DF < 10)
    {
        Num(so, result, the_knight.DF);
    }

    if (the_knight.level >= 10)
    {
        Twonum(so, result, the_knight.level);
    }
    else if (the_knight.level < 10)
    {
        Num(so, result, the_knight.level);
    }

    if (the_knight.remedy >= 10)
    {
        Twonum(so, result, the_knight.remedy);
    }
    else if (the_knight.remedy < 10)
    {
        Num(so, result, the_knight.remedy);
    }
    if (the_knight.gold >= 100)
    {
        Threenum(so, result, the_knight.gold);
    }
    else if (the_knight.gold >= 10)
    {
        Twonum(so, result, the_knight.gold);
    }
    else if (the_knight.gold < 10)
    {
        Num(so, result, the_knight.gold);
    }
    if (the_knight.phoenixdown >= 10)
    {
        Twonum(so, result, the_knight.phoenixdown);
    }
    else if (the_knight.phoenixdown < 10)
    {
        Num(so, result, the_knight.phoenixdown);
    }

    for (int i = 0; i < nEvent; i++)
    {
        int so;
        if (arr[i] >= 10)
        {
            so = arr[i] / 10;
            int2string(so, result);
            so = arr[i] % 10;
            int2string(so, result);
        }
        else
            if (arr[i] < 10)
            {
                so = arr[i];
                int2string(so, result);
            }
    }//convert to string


    string Result;
    int Count = 0;
    for (int i = 0; i < result.length(); i++)
    {
        for (int j = 0; j < result.length(); j++)
        {
            if (result[i] == result[j]) { Count++; }
        }
        if (Count == 1) { Result.push_back(result[i]); };
        Count = 0;
    }

    for (int i = 0; i < Result.length(); i++)
    {
        tong = tong + Result[i] - '0';
    }
    if (tong > 15) { return 1; }
    else { return 0; }
}

bool Check_Prime(int n)
{
    if (n < 2) {
        return false;
    }
    int count = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            count++;
        }
    }
    if (count == 0) {
        return true;
    }
    else
    {
        return false;
    }
}

bool Int_check(float a)
{
    if (a == (int)a)
        return true;
    else
        return false;
};

bool Check_HBT(int HP)
{
    double Xne = 0;
    int i = 1;
    for (i = 1; i <= HP; i++)
    {
        Xne = (-(-(pow(HP, 2)) + (2 * i * HP)) / ((2 * HP) - (2 * i)));
        if (Xne != 0)
        {
            if (Int_check(Xne)) { break; }
            ;
        }
    };
    if (Xne > 0) { return true; }
    else { return false; };
}

int startJourney(knight& theKnight, int nEvent, int* arrEvent)
{
    int GameCondition, lecu, Three_next_turn = -1, levelbase, Three_next_turn1 = -1, Five_next_turn = -1, lan_gap_mat = 0;
    double baseDamage[5] = { 1,2.5,5.5,7.5,9.5 }, Damage;
    int Gold_dorp[5] = { 10,20,30,40,50 };
    int Max_HP = theKnight.HP, j = 0, Hieuluc = 0;
    bool Successfull_save_princess = false, You_die = false, EXCALIBUR = false, Tiny = false, Frog = false, MYTHIRL = false, EXCALIPOOR = false;
    bool Arthur = false, Lancelot = false, Paladin = false, Dragon_Knight = false, Dragon_sword = false, Lancelot_With_Power_arthur = false, time_gate = false, Power_of_ODIN = false, the_first_time = false;
    if (theKnight.HP == 999) { Arthur = true; };
    if (theKnight.HP == 888) { Lancelot = true; if (theKnight.level % 2 == 1) { Lancelot_With_Power_arthur = true; }; };
    if (Check_Prime(theKnight.HP)) { Paladin = true; };
    if (Check_HBT(theKnight.HP)) { if (theKnight.HP != 888) { Dragon_Knight = true; }; }
    for (int i = 0; i < nEvent; i++)
    {
        int theEvent = arrEvent[i];
        switch (theEvent)
        {
        case MADBEAR:
        case BANDIT:
        case LORDLUPIN:
        case ELF_MONSTER:
        case TROLL:
            if (Arthur == true || Lancelot_With_Power_arthur == true || Dragon_sword == true || Paladin == true || EXCALIBUR == true || Power_of_ODIN == true)
            {
                if (theKnight.gold <= 500) { theKnight.gold += Gold_dorp[arrEvent[i] - 1]; };
                if (theKnight.level <= 10) { theKnight.level++; };
                if (theKnight.DF <= 20) { theKnight.DF++; };
                break;
            }
            if (EXCALIPOOR == true || theKnight.level < LevelEnimy(i + 1))
            {
                if (MYTHIRL == false) {
                    Damage = baseDamage[theEvent - 1] * LevelEnimy(i + 1) * 10;
                    if (Damage > theKnight.DF)
                    {
                        theKnight.HP = theKnight.HP + theKnight.DF - Damage;
                    }
                    Check_HP(theKnight.HP, theKnight.phoenixdown, Max_HP, You_die, time_gate, i, j, Frog, Tiny);
                    break;
                }
                else break;
            }
            if (EXCALIBUR == true && Tiny == false && Frog == false)
            {
                if (theKnight.gold <= 500) { theKnight.gold += Gold_dorp[arrEvent[i] - 1]; };
                if (theKnight.level <= 10) { theKnight.level++; };
                if (theKnight.DF <= 20) { theKnight.DF++; };
                break;
            }
            if (theKnight.level > LevelEnimy(i + 1))
            {
                if (theKnight.level <= 10) { theKnight.level++; };
                if (theKnight.DF <= 20) { theKnight.DF++; }
                if (theKnight.gold <= 500) { theKnight.gold += Gold_dorp[arrEvent[i] - 1]; }
                break;
            }
            else if (theKnight.level == LevelEnimy(i + 1)) { break; };


        case SHAMAN_TWICH:
            if (EXCALIPOOR == true)
            {
                if (Tiny == true || Frog == true) { break; }
                else
                {
                    Tiny = true;
                    EXCALIBUR = false;
                    Three_next_turn = Three_next_turn + 4 + i;
                    Tiny_trans(theKnight.HP);//con nhat thuoc la bien ngay
                    Use_Medicine_Remedy(theKnight.remedy, theKnight.HP, Tiny, Max_HP);
                    if (Tiny == false) { Three_next_turn = -1; }
                    Check_HP(theKnight.HP, theKnight.phoenixdown, Max_HP, You_die, time_gate, i, j, Frog, Tiny);
                }
            }
            else
                if (Arthur == true || Lancelot_With_Power_arthur == true || Dragon_sword == true || Paladin == true || Power_of_ODIN == true)
                {
                    if (theKnight.level <= 10) { theKnight.level += 2; };
                    if (theKnight.DF <= 20) { theKnight.DF += 2; };
                    break;
                }
                else
                    if (theKnight.level > LevelEnimy(i + 1))
                    {
                        if (theKnight.level <= 10) { theKnight.level += 2; };
                        if (theKnight.DF <= 20) { theKnight.DF += 2; }
                        //if (theKnight.gold <= 500) { theKnight.gold += Gold_dorp[arrEvent[i] - 1]; }
                    }
                    else if (theKnight.level == LevelEnimy(i + 1)) { break; }
                    else
                    {
                        if (Tiny == true || Frog == true) { break; }
                        else
                        {
                            Tiny = true;
                            EXCALIBUR = false;
                            Three_next_turn = Three_next_turn + 4 + i;
                            Tiny_trans(theKnight.HP);//con nhat thuoc la bien ngay
                            Use_Medicine_Remedy(theKnight.remedy, theKnight.HP, Tiny, Max_HP);
                            if (Tiny == false) { Three_next_turn = -1; }
                            Check_HP(theKnight.HP, theKnight.phoenixdown, Max_HP, You_die, time_gate, i, j, Frog, Tiny);
                        }
                    }
            break;
        case SIREN_VAJSH:
            if (EXCALIPOOR == true)
            {
                if (Tiny == true || Frog == true) { break; }
                else {
                    Frog = true;
                    EXCALIBUR = false;
                    levelbase = theKnight.level;
                    lecu = theKnight.level;
                    Three_next_turn1 = Three_next_turn1 + 4 + i;
                    Frog_trans(theKnight.level); //con nhat thuoc la bien ngay
                    Use_Medicine_Remedy1(theKnight.remedy, theKnight.level, Frog, lecu);
                    if (Frog == false) { Three_next_turn1 = -1; }
                    Check_HP(theKnight.HP, theKnight.phoenixdown, Max_HP, You_die, time_gate, i, j, Frog, Tiny);
                }
            }
            if (Arthur == true || Lancelot_With_Power_arthur == true || Dragon_sword == true || Paladin == true || Power_of_ODIN == true)
            {
                if (theKnight.level <= 10) { theKnight.level += 2; };
                if (theKnight.DF <= 20) { theKnight.DF += 2; }
                ; break;
            }
            if (theKnight.level > LevelEnimy(i + 1))
            {
                if (theKnight.level <= 10) { theKnight.level += 2; };
                if (theKnight.DF <= 20) { theKnight.DF += 2; }
                //if (theKnight.gold <= 500) { theKnight.gold += Gold_dorp[arrEvent[i] - 1]; }
            }
            else if (theKnight.level == LevelEnimy(i + 1)) { break; }
            else
            {
                if (Tiny == true || Frog == true) { break; }
                else {
                    Frog = true;
                    EXCALIBUR = false;
                    levelbase = theKnight.level;
                    lecu = theKnight.level;
                    Three_next_turn1 = Three_next_turn1 + 4 + i;
                    Frog_trans(theKnight.level); //con nhat thuoc la bien ngay
                    Use_Medicine_Remedy1(theKnight.remedy, theKnight.level, Frog, lecu);
                    if (Frog == false) { Three_next_turn1 = -1; }
                    Check_HP(theKnight.HP, theKnight.phoenixdown, Max_HP, You_die, time_gate, i, j, Frog, Tiny);
                }
            }
            break;
        case EXCALIBUR_SWORD:
            if (Dragon_sword == true) { break; }
            EXCALIBUR = true;
            EXCALIPOOR = false;
            break;
        case MYTHIRL_AMMOR:
            MYTHIRL = true;
            Five_next_turn = Five_next_turn + 8 + i;
            break;
        case EXCALIPOOR_BAD_SWORD:
            if (theKnight.level >= 5) { break; }
            if (Arthur == true || Lancelot_With_Power_arthur == true || Paladin == true || Dragon_sword == true) { break; }
            if (theKnight.level < 5) { EXCALIPOOR = true; EXCALIBUR = false; };
            break;
        case MUSH_MARIO:
            if (theKnight.HP > Max_HP - 50) { theKnight.HP = Max_HP; }
            else { theKnight.HP += 50; }
            break;
        case MUSH_FIB:
            //tang HP den so financi gan nhat
            HP_fibonacy(theKnight.HP);
            if (theKnight.HP > Max_HP) { theKnight.HP = Max_HP; }
            break;
        case MUSH_GHOST:
            if (Paladin == true || Dragon_sword == true) { break; }
            HP_DF_Mushghost(theKnight.HP, theKnight.DF);
            break;
        case MUSH_KNIGHT:
            if (theKnight.HP > 999 - 50) { Max_HP = 999; }
            else { Max_HP += 50; }
            theKnight.HP = Max_HP;
            break;
        case REMEDY_POSION:
            if (theKnight.remedy != 99) { theKnight.remedy++; }
            if (Tiny) { Use_Medicine_Remedy(theKnight.remedy, theKnight.HP, Tiny, Max_HP); }
            if (Frog) { Use_Medicine_Remedy1(theKnight.remedy, theKnight.level, Frog, lecu); }
            break;
        case PHOENIX_DOWN:
            if (theKnight.phoenixdown != 99) { theKnight.phoenixdown++; } //chua chek th nhat thuoc sd ngay lap tuc
            break;
        case MERLIN_50:
            if (Tiny == true || Frog == true) { Tiny == false; Frog == false; }
            if (theKnight.level < 10) { theKnight.level++; };
            theKnight.HP = Max_HP;
            break;
        case NINA_THE_RING:
            if (Check_friendly_num(theKnight.HP, theKnight.gold))
            {
                if (Tiny == true) { Back_to_normal_size(theKnight.HP, Max_HP); Tiny = false; };
                if (Frog == true) { Back_to_level(theKnight.HP, levelbase); Frog = false; };
                break;
            }
            else
            {
                if (theKnight.gold < 50) { break; }
                if (theKnight.gold >= 50)
                {
                    if (Tiny == true) { theKnight.gold -= 50; Back_to_normal_size(theKnight.HP, Max_HP); Tiny = false; };
                    if (Frog == true) { theKnight.gold -= 50; Back_to_level(theKnight.HP, levelbase); Frog = false; };
                    theKnight.HP += theKnight.gold;

                    if (theKnight.HP > Max_HP) {
                        theKnight.gold = theKnight.gold - theKnight.gold + (theKnight.HP - Max_HP);
                        theKnight.HP = Max_HP;
                    }
                    else theKnight.gold = 0;
                }
            }
            break;
        case ABYSS:
            if (Dragon_sword == true) { break; }
            if (theKnight.level >= 7) { break; }
            if (theKnight.gold >= 50) { theKnight.gold -= 50; break; }
            if (theKnight.gold < 50) {
                if (Giai_mat_ma(arrEvent, theKnight, nEvent) == 1)
                {
                    break;
                }
                else { You_die = true; }
                ;
            }
            break;

        case TIME_GATE:
            time_gate = true;
            j = i;
            break;
        case GUINEVERE:
            nEvent = i * 2 + 1;
            arrEvent[nEvent + 1];
            for (int j = 1; j <= i; j++)
            {
                arrEvent[i + j] = arrEvent[i - j];
            }
            break;
        case LIGHT_WING:
            if (i + 3 > nEvent) { Successfull_save_princess = true; }
            if (arrEvent[i + 1] == BOWSER_GIVE_UP || arrEvent[i + 2] == BOWSER_GIVE_UP || arrEvent[i + 3] == BOWSER_GIVE_UP) { Successfull_save_princess = true; }
            else if (arrEvent[i + 1] == GUINEVERE || arrEvent[i + 2] == GUINEVERE || arrEvent[i + 3] == GUINEVERE) { Successfull_save_princess = true; }
            else if (i + 4 <= nEvent) { i += 3; }

            break;
        case ODIN:
            if (the_first_time == false)
            {
                Power_of_ODIN = true;
                Hieuluc = i + 3;
                the_first_time = true;
            }
            break;
        case DRAGON_SWORD:
            if (Dragon_Knight) { Dragon_sword = true; }
            break;
        case MEET_BOWSER:
            if (Arthur == true || Lancelot == true || Power_of_ODIN == true) { theKnight.level = 10; break; }
            if (Paladin) {
                if (theKnight.level >= 8)
                {
                    theKnight.level = 10;
                    break;
                }
                else { You_die = true; }
            }
            else if (theKnight.level == 10)
            {
                break;
            }
            else if (Dragon_Knight)
            {
                if (Dragon_sword)
                {
                    theKnight.level = 10;
                    break;
                }
                else { You_die = true; };
            }
            else { You_die = true; }
            break;
        case BOWSER_GIVE_UP:
            Successfull_save_princess = true;
            break;
        }
        Check_DF_HP_Gold_level(theKnight.HP, theKnight.DF, theKnight.gold, theKnight.level, Max_HP);

        //if (Check_HBT(theKnight.HP)) { if (theKnight.HP != 888) { Dragon_Knight = true; } }
        //else { Dragon_Knight = false; Dragon_sword = false; };
        //if (Check_Prime(theKnight.HP)) { Paladin = true; }
        //else { Paladin = false; };
        //if (theKnight.HP == 999) { Arthur = true; }
        //else if (theKnight.HP != 999) { Arthur = false; }
        if (Hieuluc == i) { Power_of_ODIN = false; }
        if (Lancelot == true) { Lancelot = true; if (theKnight.level % 2 == 1) { Lancelot_With_Power_arthur = true; } else { Lancelot_With_Power_arthur = false; }; }
        //else if (theKnight.HP != 888) { Lancelot = false; Lancelot_With_Power_arthur = false; };
        if (Successfull_save_princess) { break; }
        if (You_die) { break; }
        if (Three_next_turn == i) { Back_to_normal_size(theKnight.HP, Max_HP); Three_next_turn = -1; Tiny = false; }
        if (Three_next_turn1 == i) { Back_to_level(theKnight.level, levelbase); Three_next_turn1 = -1; Frog = false; }
        if (Five_next_turn == i) { MYTHIRL = false; Five_next_turn = -1; }

    }



    GameCondition = theKnight.gold + theKnight.HP + theKnight.DF + theKnight.level + theKnight.phoenixdown + theKnight.remedy;
    if (GameCondition > 0) { if (You_die) { return -1; } else { return GameCondition; }; }
    else { return -1; }
}//final