#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Nightlight {
    int *i_pointer;
    string *s_pointer;
    bool* b_pointer;
    ifstream readFile;
protected:
    static int count;
public:

    Nightlight(
            int price = 1490,
            int weight = 450,
            int power = 10,
            int voltage = 12,
            string brand = "IKEA",
            string producing_country = "China",
            string model = "MERKREDD",
            bool phoneApp_control = false,
            bool have_touch_control = false,
            bool switch_colours = false,
            int colour = 0,//var of state
            bool turn_on_off_light = false,//var of state
            bool phone_is_connected = false//var of state
    )
    {   b_pointer=new bool[5];
        i_pointer = new int[5];
        s_pointer = new string[3];
        b_pointer[0]=have_touch_control;
        b_pointer[1]=phoneApp_control;
        b_pointer[2]=switch_colours;
        b_pointer[3] = turn_on_off_light;
        b_pointer[4] = phone_is_connected;
        i_pointer[0] = price;
        i_pointer[1] = power;
        i_pointer[2] = voltage;
        i_pointer[3] = weight;
        i_pointer[4] = colour;
        s_pointer[0] = brand;
        s_pointer[1] = producing_country;
        s_pointer[2] = model;

                count++;
    }

    Nightlight(const string file) {
        readFile.open(file);
        b_pointer=new bool[5];
        i_pointer = new int[5];
        s_pointer = new string[3];
        if (readFile.is_open()) {
            cout << "\nInitialization from file\n" << endl;
            readFile >> i_pointer[0];//price
            readFile >> i_pointer[1];//weight
            readFile >> i_pointer[2];//power
            readFile >> i_pointer[3];//voltage
            readFile >> s_pointer[0];//brand
            readFile >> s_pointer[1];//country
            readFile >> s_pointer[2];//model
            readFile >> b_pointer[0];//have_touch_control
            readFile >> b_pointer[1];//bool phoneApp_control
            readFile >> b_pointer[2];//bool switch_colours
            readFile >> i_pointer[4];//var of state
            readFile >> b_pointer[3];//var of state
            readFile >> b_pointer[4];//var of state
            count++;
        } else {
            cout << "Impossible to open file \n\n";
            i_pointer[0] = 1490;//price
            i_pointer[1] = 450;//weight
            i_pointer[2]= 10;//power
            i_pointer[3] = 12;//voltage
            s_pointer[0]= "IKEA";//brand
            s_pointer[1]= "China";//country
            s_pointer[2] = "MERKREDD";//model
            b_pointer[0]= false;//phoneApp_control
            b_pointer[1]= false;//have_touch_control
            b_pointer[2]= false;//switch_colours;
             i_pointer[4] = 0;//colour - var of state
             b_pointer[3]= false;//turn_on_off_light - var of state
             b_pointer[4]= false;//phone_is_connected - var of state
            count++;
        }

    }

    Nightlight(const Nightlight &nightlight){
        b_pointer=new bool[5];
        i_pointer = new int[5];
        s_pointer = new string[3];
        i_pointer[0] = nightlight.i_pointer[0];//price
        i_pointer[1] = nightlight.i_pointer[1];//weight
        i_pointer[2] = nightlight.i_pointer[2];//power
        i_pointer[3] = nightlight.i_pointer[3];//voltage
        s_pointer[0] = nightlight.s_pointer[0];//brand
        s_pointer[1] = nightlight.s_pointer[1];//country
        s_pointer[2] = nightlight.s_pointer[2];//model
        b_pointer[0] = nightlight.b_pointer[0];//phoneApp_control
        b_pointer[1] = nightlight.b_pointer[1];//have_touch_control
        b_pointer[2] = nightlight.b_pointer[2];//switch_colours;
        i_pointer[4] = nightlight.i_pointer[4];//colour - var of state
        b_pointer[3] = nightlight.b_pointer[3];//turn_on_off_light - var of state
        b_pointer[4] = nightlight.b_pointer[4];//phone_is_connected - var of state
    }

    void switchOn();

    void switchOff();

    void connectToPhone();

    void setModeOfLight(int colour);

    friend ostream &operator<<(ostream &, Nightlight *);

    ~Nightlight() {
        if (readFile.is_open()) readFile.close();

        if (count == 0) {
            cout << "\nThere are no classes to delete\n";
            exit(0);
        }
        cout << "Was deleted: " << s_pointer[0] << endl;
        count--;
        delete[] s_pointer;
        delete[] i_pointer;
        delete[] b_pointer;
    };
};


ostream &operator<<(ostream &stream, Nightlight *nightlight) {
    stream << "Price = " << nightlight->i_pointer[0] << " ru" << endl;
    stream << "Weight = " << nightlight->i_pointer[1] << " grams" << endl;
    stream << "Power = " << nightlight->i_pointer[2] << " W" << endl;
    stream << "Voltage = " << nightlight->i_pointer[3] << " V" << endl;
    stream << "Brand is " << nightlight->s_pointer[0] << endl;
    stream << "The model is " << nightlight->s_pointer[2] << endl;
    stream << "Producing country is " << nightlight->s_pointer[1]<< endl;

    if (nightlight->b_pointer[0])
        stream << "\nThe nightlight type have touch control" << endl;
    else
        stream << "\nThe nightlight type can be control only with buttons" << endl;
    if (nightlight->b_pointer[1])
        stream << "The nightlight type can be control from phone" << endl;
    else
        stream << "The nightlight type can't be control from phone" << endl;
    if (nightlight->b_pointer[2])
        stream
                << "It is available a range of colours of light: YELLOW(0), RED(1), BLUE(2), GREEN(3), WHITE(4) or ALL(5)"
                << endl;
    else
        stream << "It is available only one color of light: YELLOW" << endl;
    stream << "------------------------------------------------------------" << endl;
    return stream;
}

void Nightlight::switchOn() {
    if (!b_pointer[3]) {
        cout << "The nightlight is TURN OFF, TURNING ON the light" << endl;
        cout << "TURN ON\n------------------------------------------------------------" << endl;
        b_pointer[3]= true;
    } else return;
}

void Nightlight::switchOff() {
    if (b_pointer[3]) {
        cout << "The nightlight is TURN ON, TURNING OFF the light" << endl;
        cout << "TURN OFF\n------------------------------------------------------------" << endl;
        b_pointer[3] = false;
    } else return;
}

void Nightlight::connectToPhone() {
    if (b_pointer[3]) {
        if (b_pointer[0]) {
            if (b_pointer[4]) {
                cout << "Your phone has already connected!" << endl;
            } else {
                cout << "Connecting your phone to the lamp" << endl;
                b_pointer[4] = true;
            }
        } else return;
        cout << "------------------------------------------------------------" << endl;
    } else {
        switchOn();
    }
}

void Nightlight::setModeOfLight(int colour) {
    if (b_pointer[2]) {
        switch (colour) {
            case 0: {
                cout << "Turn on YELLOW COLOUR" << endl;
                break;
            }
            case 1: {
                cout << "Turn on RED COLOUR" << endl;
                break;
            }
            case 2: {
                cout << "Turn on BLUE COLOUR" << endl;
                break;
            }
            case 3: {
                cout << "Turn on GREEN COLOUR" << endl;
                break;
            }
            case 4: {
                cout << "Turn on WHITE COLOUR" << endl;
                break;
            }
            case 5: {
                cout << "Turn on YELLOW COLOUR" << endl;
                cout << "Turn on RED COLOUR" << endl;
                cout << "Turn on BLUE COLOUR" << endl;
                cout << "Turn on GREEN COLOUR" << endl;
                cout << "Turn on WHITE COLOUR" << endl;
            }
        }
    } else
        cout << "Turn on YELLOW COLOUR" << endl;

    cout << "------------------------------------------------------------" << endl;
}

int Nightlight::count = 0;

int main() {

    cout << "\nTHE SMART NIGHTLIGHT" << endl;
    Nightlight nightlight_smart(5000, 600, 20, 12, "Xiaomi", "China", "Yeelight Smart Atmosphere",
                                true, true, true, 2, false, false);
    cout << &nightlight_smart;
    nightlight_smart.switchOn();
    nightlight_smart.connectToPhone();//connect phone
    nightlight_smart.connectToPhone();//show that phone has been already connected
    nightlight_smart.setModeOfLight(5);
    nightlight_smart.switchOff();


    cout << "\nTHE NIGHTLIGHT FOR KIDS" << endl;
    Nightlight nightlight_kids(3500, 550, 10, 12, "MotionLamps", "Russia", "GalaxyRGB",
                               false, true, true, 2, false, false);
    cout << &nightlight_kids;
    nightlight_kids.switchOn();
    nightlight_kids.connectToPhone();//show that function won't work with that configuration // we can delete this
    nightlight_kids.setModeOfLight(2);
    nightlight_kids.switchOff();

    //Initialization from file
    cout << "\nTHE SIMPLE NIGHTLIGHT" << endl;
    Nightlight simple_nightlight("nightlight.txt"); //work of default constructor
    cout << &simple_nightlight;
    simple_nightlight.switchOn();
    simple_nightlight.connectToPhone();//won't be work with that configuration, we // we can  delete this
    simple_nightlight.setModeOfLight(
            4);//won't be work with that configuration, the light will be only yellow // we can set every color for parameter.
    simple_nightlight.switchOff();

    return 0;
}
