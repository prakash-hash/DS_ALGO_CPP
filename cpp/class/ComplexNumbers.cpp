class ComplexNumbers {
	// Complete this class
    private:
        int re;		//real
        int img;	//imaginary

    public:
    //Constructor
        ComplexNumbers(int re, int img)
        {
            this->re = re;
            this->img = img;
        }

    void Plus(ComplexNumbers C2)
    {
        this->re += C2.re;
        this->img += C2.img;
    }

    void multiply(ComplexNumbers C2)
    {
        int r = (this->real * C2.real) - (this->imaginary * c_2.imaginary);
        int i = (this->real * C2.imaginary) + (this->imaginary * c_2.real);
        this->real=r;
        this->imaginary =i;
    }

    void print()
    {
        if(imaginary<0){
            cout<<real<<" - "<<"i"<<imaginary*-1<<endl;
        }
        else{
        cout<<real<<" + "<<"i"<<imaginary<<endl;
        }
    }

};