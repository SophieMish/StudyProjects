#include <iostream>
#include <string>
#include <fstream>

#include <iostream>
#include <string>
#include <fstream>

using namespace std;




class Lamps {
protected:
    string date_of_manufacture;
    double guarantee_period;//years
    double life_time;//years
    string type_of_light_element;//LED,Bulb,energy saving lamps and etc
    bool light_bulb;//Is the lamp sold with a bulb
    fstream readFile;
public:
    Lamps(
            double guarantee_period = 1.5,
            double life_time = 3.5,
            string date_of_manufacture = "01.05.2020",
            string type_of_light_element="LED",
            bool light_bulb=true
    ):
            guarantee_period(guarantee_period),
            life_time(life_time),
            date_of_manufacture(date_of_manufacture),
            type_of_light_element(type_of_light_element),
            light_bulb(light_bulb){}

    Lamps(const string file) {
        readFile.open(file);
        if (readFile.is_open()) {
            cout << "Initialization general properties from file..." << endl;
            readFile >> date_of_manufacture;
            readFile >> guarantee_period;
            readFile >> life_time ;
            readFile >> type_of_light_element;
            readFile >> light_bulb;
        } else {
            cout << "Impossible to open file \n\n";
            date_of_manufacture = "01.05.2020";
            guarantee_period = 1.5;
            life_time = 3.5;
            type_of_light_element="LED";
            light_bulb=true;
        }
    }

    Lamps(const Lamps &lamp) :
            date_of_manufacture(lamp.date_of_manufacture),
            guarantee_period(lamp.guarantee_period),
            life_time(lamp.life_time),
            type_of_light_element(lamp.type_of_light_element),
            light_bulb(lamp.light_bulb)
    {}

    virtual void install_light_bulb(){
        if(light_bulb){
            cout<<"Installing a light bulb in a lamp holder"<<endl;
        } else {
            cout<<"There are no light bulb in the kit. You should buy it."<<endl;
        }
        cout << "------------------------------------------------------------" << endl;
    }

    virtual ~Lamps() {
        cout << "Calling virtual destructor of lamps" << endl;
    }
};


class Nightlight:public Lamps{
    int power;
    int voltage;
    int weight;
    int price;
    string brand;
    string producing_country;
    string model;
    bool have_touch_control;
    bool phoneApp_control;
    bool switch_colours;
    int colour;//var of state
    bool turn_on_off_light;//var of state
    bool phone_is_connected;//var of state
public:
    static int count;
    Nightlight(
            double guarantee_period = 1.5,
            double life_time = 3.5,
            string date_of_manufacture = "01.05.2020",
            string type_of_light_element="LED",
            bool light_bulb=true,
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
    ) :
            price(price),
            power(power),
            voltage(voltage),
            weight(weight),
            have_touch_control(have_touch_control),
            phoneApp_control(phoneApp_control),
            brand(brand),
            producing_country(producing_country),
            model(model),
            switch_colours(switch_colours),
            colour(colour),
            turn_on_off_light(turn_on_off_light),
            phone_is_connected(phone_is_connected),
            Lamps(guarantee_period,life_time,date_of_manufacture,type_of_light_element,light_bulb){count++;}

    Nightlight(const string file):Lamps(file) {
        if (readFile.is_open()) {
            cout << "Initialization individual properties from file...\n" << endl;
            readFile >> price;
            readFile >> power;
            readFile >> voltage;
            readFile >> weight;
            readFile >> brand;
            readFile >> producing_country;
            readFile >> model;
            readFile >> have_touch_control;
            readFile >> phoneApp_control;
            readFile >> switch_colours;
            readFile >> colour;//var of state
            readFile >> turn_on_off_light;//var of state
            readFile >> phone_is_connected;//var of state

        } else {
            cout << "Impossible to open file \n\n";
            price = 1490;
            weight = 450;
            power = 10;
            voltage = 12;
            brand = "IKEA";
            producing_country = "China";
            model = "MERKREDD";
            phoneApp_control = false;
            have_touch_control = false;
            switch_colours = false;
            colour = 0;//var of state
            turn_on_off_light = false;//var of state
            phone_is_connected = false;//var of state
        }
        count++;
    }

    Nightlight(const Nightlight &nightlight) :
            price(nightlight.price),
            weight(nightlight.weight),
            power(nightlight.power),
            voltage(nightlight.voltage),
            phoneApp_control(nightlight.phoneApp_control),
            have_touch_control(nightlight.have_touch_control),
            brand(nightlight.brand),
            producing_country(nightlight.producing_country),
            model(nightlight.model),
            switch_colours(nightlight.switch_colours),
            colour(nightlight.colour),
            turn_on_off_light(nightlight.turn_on_off_light),
            phone_is_connected(nightlight.phone_is_connected),
            Lamps(nightlight){
    }

    void switchOn();

    void switchOff();

    void connectToPhone();

    void setModeOfLight(int colour);

    friend ostream &operator<<(ostream &, Nightlight*);

    ~Nightlight()
    {
        if(readFile.is_open()) readFile.close();
        if(count==0){
            cout<<"There are no classes to delete\n";
            exit(0);
        } else if (count!=0){
            cout<<"Was deleted: "<<brand<<"\n";
            count--;
        }
    };
};


ostream &operator<<(ostream &stream, Nightlight *nightlight) {
    stream <<"Date of manufacture: "<<nightlight->date_of_manufacture<<endl;
    stream <<"Guarantee period: "<<nightlight->guarantee_period<<" years"<<endl;
    stream <<"The period of life: "<<nightlight->life_time<<" years"<<endl;
    stream <<"The type of artificial light source: "<<nightlight->type_of_light_element<<endl;
    if(nightlight->light_bulb){
        stream <<"Lamp has a light bulb in the kit "<<endl;
    } else {
        stream <<"Lamp has not a light bulb in the kit "<<endl;
    }
    stream << "Price = " << nightlight->price << " ru" << endl;
    stream << "Weight = " << nightlight->weight << " grams" << endl;
    stream << "Power = " << nightlight->power << " W" << endl;
    stream << "Voltage = " << nightlight->voltage << " V" << endl;
    stream << "Brand is " << nightlight->brand << endl;
    stream << "The model is " << nightlight->model << endl;
    stream << "Producing country is " << nightlight->producing_country << endl;

    if (nightlight->have_touch_control)
        stream << "\nThe nightlight type have touch control" << endl;
    else
        stream << "\nThe nightlight type can be control only with buttons" << endl;
    if (nightlight->phoneApp_control)
        stream << "The nightlight type can be control from phone" << endl;
    else
        stream << "The nightlight type can't be control from phone" << endl;
    if (nightlight->switch_colours)
        stream
                << "It is available a range of colours of light: YELLOW(0), RED(1), BLUE(2), GREEN(3), WHITE(4) or ALL(5)"
                << endl;
    else
        stream << "It is available only one color of light: YELLOW" << endl;
    stream << "------------------------------------------------------------" << endl;
    return stream;
}

void Nightlight::switchOn() {
    if (!turn_on_off_light) {
        cout << "The nightlight is TURN OFF, TURNING ON the light" << endl;
        cout << "TURN ON\n------------------------------------------------------------" << endl;
        turn_on_off_light = true;
    } else return;
}

void Nightlight::switchOff() {
    if (turn_on_off_light) {
        cout << "The nightlight is TURN ON, TURNING OFF the light" << endl;
        cout << "TURN OFF\n------------------------------------------------------------" << endl;
        turn_on_off_light = false;
    } else return;
}

void Nightlight::connectToPhone() {
    if (turn_on_off_light) {
        if (phoneApp_control) {
            if (phone_is_connected) {
                cout << "Your phone has already connected!" << endl;
            } else {
                cout << "Connecting your phone to the lamp" << endl;
                phone_is_connected = true;
            }
        } else return;
        cout << "------------------------------------------------------------" << endl;
    } else {
        switchOn();
    }
}

void Nightlight::setModeOfLight(int colour) {
    if (switch_colours) {
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

    cout << "\nTHE SMART NIGHTLIGHT\n" << endl;
    Nightlight nightlight_smart(1,4.5,"05.06.2020","LED",true,5000, 600, 20, 12, "Xiaomi", "China", "Yeelight Smart Atmosphere",
                                true, true, true, 2, false, false);
    cout << &nightlight_smart;
    nightlight_smart.install_light_bulb();
    nightlight_smart.switchOn();
    nightlight_smart.connectToPhone();//connect phone
    nightlight_smart.connectToPhone();//show that phone has been already connected
    nightlight_smart.setModeOfLight(5);
    nightlight_smart.switchOff();



    cout << "\nTHE NIGHTLIGHT FOR KIDS\n" << endl;
    Nightlight nightlight_kids(2.5,3,"05.04.2020","Incandescent",false,3500, 550, 10, 12, "MotionLamps", "Russia", "GalaxyRGB",
                               false, true, true, 2, false, false);
    cout << &nightlight_kids;
    nightlight_kids.install_light_bulb();
    nightlight_kids.switchOn();
    nightlight_kids.connectToPhone();//show that function won't work with that configuration // we can delete this
    nightlight_kids.setModeOfLight(2);
    nightlight_kids.switchOff();

    //Initialization from file
    cout << "\nTHE SIMPLE NIGHTLIGHT (file)\n" << endl;
    Nightlight simple_nightlight("nightlight.txt");
    cout << &simple_nightlight;
    simple_nightlight.install_light_bulb();
    simple_nightlight.switchOn();
    simple_nightlight.connectToPhone();//won't be work with that configuration, we // we can  delete this
    simple_nightlight.setModeOfLight(4);//won't be work with that configuration, the light will be only yellow // we can set every color for parameter.
    simple_nightlight.switchOff();

    cout << "The number of objects to delete:"<< Nightlight::count<<"\n\n";


}