#include<bits/stdc++.h>
using namespace std;

enum class vehicleType{
    CAR, 
    BIKE,
    TRUCK
};

class vehicle{ 

    string plate_number;
    vehicleType type;

    public:
        vehicle(string plt_num, vehicleType t): plate_number(plt_num), type(t) {}

        vehicleType getType() const{
            return type;
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

};

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
                return true;
            }
        }
        return false;
    }




};

int main(){
    vehicle car("HR26AB1234", vehicleType::CAR);
    vehicle v1("HWqwq3872", vehicleType::BIKE);

    parkingLot lot1;
    if(lot1.parkVehicle(&car)){
        cout<<"vehicle parked";
    }

    return 0;
}