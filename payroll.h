#ifndef PAYROLL_H
#define PAYROLL_H
#define hours 8

class payroll
{
	private:
		int wh;
		float basic, allowance, netsalary;
		
	public:
		payroll()
		{
			wh=0;
			basic=allowance=netsalary=0;
		}
	
		void setWD()
		{
			cout << "Enter the number of hours worked this month ->";
			cin >> wh;	
		}
		
	
		void setBasic(string base)
		{
			basic = atof(base.c_str());
		}
		
		void setAllowance()			//bonus apply when working hours > 40
		{
			float bonus,OT;
			OT = (wh - 40) * 10;
			bonus = basic * 0.05;
			allowance = OT + bonus;
		}
		
		float calcGrossPay()
		{
			netsalary = (basic + allowance);
			return netsalary;
		}
		
		int getWD(){return wh;};
		float getAllowance(){return allowance;};
};

#endif
