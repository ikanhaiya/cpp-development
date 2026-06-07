#include<bits/stdc++.h>
using namespace std;


enum class vehicleType{
    CAR, 
    BIKE,
    TRUCK
};

ostream& operator<<(ostream& os, vehicleType type){
    switch(type)
    {                                  // os: output stream 
        case vehicleType::CAR:
            os << "CAR";
            break;

        case vehicleType::BIKE:
            os << "BIKE";
            break;

        case vehicleType::TRUCK:
            os << "TRUCK";
            break;
    }

    return os;  /* this return is done for operator chaining cout<<vehicleType<<"parked"; 
     so when cout<<vehicleType is converted to operator<<(cout,vehicletype) if it return cout then only cout<<"parked"; will be done*/
}


class vehicle{ 

    string plate_number;
    vehicleType type;

    public:
        vehicle(string plt_num, vehicleType t): plate_number(plt_num), type(t) {}

        vehicleType getType() const{
            return type;
        }

        string getPlateNumber(){
            return plate_number;
        }

};

class parkingSpot{

    int spotNo;
    vehicleType spotType; 
    vehicle* parkedVehicle;

    public: 

        parkingSpot(int num,vehicleType type) : spotNo(num),spotType(type), parkedVehicle(nullptr){} 

        bool isAvailable() const {
            return parkedVehicle == nullptr;   // this function tells whether spot is available if parkedVehicle == nullptr then spot available 
        }

        bool parkVehicle(vehicle* v){

            if(!isAvailable()){
                return false;
            }

            if(v->getType() != spotType){
                return false;
            }

            parkedVehicle = v;
            return true;
        }
        void removeVehicle() {
             parkedVehicle = nullptr;
        }

        int getSpotNo() const {
            return spotNo;
        }

        vehicleType getSpotType() const {
            return spotType;
        }

        string getPlateNumber(){
            return parkedVehicle->getPlateNumber();
        }

};

class createTicket{

    static int nextTicketId;
    int ticketId;
    time_t entryTime;
    parkingSpot* spot; // parkingSpot has spot number , spot type and parked vehicle 

    public: 
        
        createTicket( time_t etime,parkingSpot* spt) : entryTime(etime), spot(spt) {
            ticketId = nextTicketId++; 
        }

        // displaying the ticket information
        
        void display(){
            cout<<"Ticket ID:    "<<ticketId<<endl;
            cout<<"Entry time:   "<<entryTime<<endl;
            cout<<"Spot type:    "<<spot->getSpotType()<<endl;
            cout<<"Spot Number:  "<<spot->getSpotNo()<<endl;
            cout<<"Plate Number: "<<spot->getPlateNumber()<<endl;
        }

};
int createTicket::nextTicketId = 0;

class parkingLot{
    /* Its job is:

        1> Store parking spots.
        2> Find a suitable free spot.
        3> Ask that spot to park the vehicle.*/
    
    vector<parkingSpot> spots;
    public:
    parkingLot() {
        spots.push_back(parkingSpot(1, vehicleType::CAR));
        spots.push_back(parkingSpot(2, vehicleType::CAR));
        spots.push_back(parkingSpot(3, vehicleType::BIKE));
        spots.push_back(parkingSpot(4, vehicleType::TRUCK));
    }

    bool parkVehicle(vehicle* v){
        
        // check if any spot is available for vehicle type v
        for(parkingSpot sp : spots){
            if(sp.parkVehicle(v)){
                createTicket ticket1(time(nullptr), &sp);
                ticket1.display();
                return true;
            }
        }
        return false;
    }
};


int main(){
    vehicle car("HR26AB1234", vehicleType::CAR);
    vehicle bike("HWqwq3872", vehicleType::BIKE);
    vehicle truck("afsdfa", vehicleType::TRUCK);

    parkingLot lot1;
    
    lot1.parkVehicle(&car);
    lot1.parkVehicle(&bike);
    

    return 0;
}