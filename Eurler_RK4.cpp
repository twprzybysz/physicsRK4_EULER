#include "stdafx.h"
#include <iostream>

using namespace std;

void Euler (float& position, float& velocity, float dt, float mass, float force)
{
	velocity = dt * (mass/force) + velocity;
	position = dt * velocity + position; 
}

void RK4 (float& position, float& velocity, float dt, float mass, float T, float C)
{
	float k1 = dt *( 1.0f/mass * ( T - C * velocity) );
	float k2 = dt *( 1.0f/mass * ( T - C * (velocity + k1 /2.0f)) );
	float k3 = dt *( 1.0f/mass * ( T - C * (velocity + k2 /2.0f)) );
	float k4 = dt *( 1.0f/mass * ( T - C * (velocity + k3 )) );

	velocity = velocity + (1.0/6.0f) * ( k1 + 2 * k2 + 2 * k3 + k4 );
	position = dt * velocity + position; 
}


int main()
{
	{
		cout << "EURLER STEP 1 second" << endl;
		
		float velocity = 0.0f;
		float pos = 0.0f;
		float dt = 1.0f;
		float mass = 10.0f;
		float force = 4.0f;
	
		cout << "STEP\tPOSITION\tVELOCITY"<< endl;
		for ( int i= 0; i<10; i++ )
		{
			Euler(pos, velocity,dt, mass, force);
			cout << i <<"\t"<< pos<< "\t" << velocity << endl;
		}		
	}

	{
		cout << "EURLER STEP 0.5 second" << endl;
		
		float velocity = 0.0f;
		float pos = 0.0f;
		float dt = 0.5f;
		float mass = 10.0f;
		float force = 4.0f;
	
		cout << "STEP\tPOSITION\tVELOCITY"<< endl;
		for ( int i= 0; i<20; i++ )
		{
			Euler(pos, velocity,dt, mass, force);
			cout << i <<"\t"<< pos<< "\t" << velocity << endl;
		}		
	}

	{
		cout << "EURLER STEP 0.25 second" << endl;
		
		float velocity = 0.0f;
		float pos = 0.0f;
		float dt = 0.25f;
		float mass = 10.0f;
		float force = 4.0f;
	
		cout << "STEP\tPOSITION\tVELOCITY"<< endl;
		for ( int i= 0; i<40; i++ )
		{
			Euler(pos, velocity,dt, mass, force);
			cout << i <<"\t"<< pos<< "\t" << velocity << endl;
		}		
	}

	{
		cout << "RK4 STEP 1 SECOND" << endl;
		//RK4
		float pos = 0.0f;
		float velocity = 0.0f;
		float dt = 1.0f;
		float m = 100.0f;

		float T = 100.0f; //napêd
		float C = 1.0f; //opór
	
		//step
		cout << "STEP\tPOSITION\tVELOCITY"<< endl;
		for ( int i= 0; i<10; i++ )
		{
			RK4(pos, velocity,dt,m,T,C);
			cout<< i << "\t" << pos << "\t" << velocity << endl;
		}
	}
	{
		cout << "RK4 STEP 0.5 SECOND" << endl;
		//RK4
		float pos = 0.0f;
		float velocity = 0.0f;
		float dt = 0.5f;
		float m = 100.0f;

		float T = 100.0f; //napêd
		float C = 1.0f; //opór
	
		//step
		cout << "STEP\tPOSITION\tVELOCITY"<< endl;
		for ( int i= 0; i<20; i++ )
		{
			RK4(pos, velocity,dt,m,T,C);
			cout<< i << "\t" << pos << "\t" << velocity << endl;
		}
	}
	{
		cout << "RK4 STEP 0.25 SECOND" << endl;
		//RK4
		float pos = 0.0f;
		float velocity = 0.0f;
		float dt = 0.25f;
		float m = 100.0f;

		float T = 100.0f; //napêd
		float C = 1.0f; //opór
	
		//step
		cout << "STEP\tPOSITION\tVELOCITY"<< endl;
		for ( int i= 0; i<40; i++ )
		{
			RK4(pos, velocity,dt,m,T,C);
			cout<< i << "\t" << pos << "\t" << velocity << endl;
		}
	}

	system("Pause");
	return 0;
}

