class ParkingSystem {
    private int remainBig;
    private int remainMedium;
    private int remainSmall;
    
    public ParkingSystem(int big, int medium, int small) {
        this.remainBig = big;
        this.remainMedium = medium;
        this.remainSmall = small;
    }
    
    public boolean addCar(int carType) {
        if(carType == 1) {
            if(remainBig == 0) {
                return false;
            }
            remainBig--;
        } else if(carType == 2) {
            if(remainMedium == 0) {
                return false;
            }
            remainMedium--;
        } else if(carType == 3) {
            if(remainSmall == 0) {
                return false;
            }
            remainSmall--;
        } 

        return true;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */