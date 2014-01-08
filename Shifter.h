class Shifter {
private:
	// Stuff to define the actual pneumatics
public:
	// Constructor:
	Shifter();
	
	// Destructor:
	~Shifter();
	
	// Functions:
	void LowGear();
	void HighGear();
	void ToggleGear();
	
	int CurrentGear();
};
