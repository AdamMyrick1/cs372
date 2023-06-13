class addone 
{
    private: 
        int number;
    public:
        addone(int initValue) : number(initValue) {};

        int incrementNumber()
        {
            number += 1;
            return number;
        }
};