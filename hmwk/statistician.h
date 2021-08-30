#ifndef STATISTICIAN_H
#define STATISTICIAN_H

class Statistician{
	public:
	
	Statistician();
	Statistician(Statistician const& s);
	Statistician& operator= (Statistician const& s);
	Statistician operator+ ( Statistician& s);

	int get_length() const;
	double get_lastNum() const;
	double get_sum() const;
	double get_min() const;
	double get_max() const;
	
	void set_length (double length);
	void set_lastNum(double lastNum);
	void set_sum(double sum);
	void set_min(double min);
	void set_max(double max);
	double mean() const;

	void next_number(double n);
	void erase();
	void print() const;

	private:
	double lastNum;
	int length;
	double sum;
	double min_value;
	double max_value;
	
};
#endif
