#include "PointProjection.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>
#include "EasyBMP.h" 
#include "vec.h" 
#include <map>

typedef std::pair<vec3, vec3> spline;  
typedef std::pair<vec2, vec2> projectline; 


PointProjection::PointProjection()  
{
}

PointProjection::PointProjection(vec3 _persCam, vec3 _viewDir)  
{
	persCam = _persCam;
	viewDir = _viewDir;
}

void PointProjection::depthOrder(vector<vector<vec3>> &splineSets)
{
}

void PointProjection::ThreeDtoTwoD ()
{
	/*
    BMP output; 
	output.SetSize(640, 480);
	output.SetBitDepth (24);

	
    //calculate everything here     
	int resoX = 640; 
	int resoY = 480; 
	float FOVY = 45.0; 
	float PI = 3.141592; 
	float vdirX = 0.0; 
	float vdirY = 0.0; 
	float vdirZ = -1.0; 
	float uVecX = 0.0; 
	float uVecY = 1.0; 
	float uVecZ = 0.0; 


	vec3 E = vec3 (0, 0, 200); 
	float tanTheta = tan(FOVY*PI/180); 
	float yDistance = (resoY/2)/tanTheta; 
	float tanPhi = (resoX/2)/yDistance; 
	vec3 C = vec3(yDistance*vdirX, yDistance*vdirY, yDistance*vdirZ);     
	vec3 M = E + C; 
	vec3 U = vec3(uVecX, uVecY, uVecZ); 
	vec3 A = C.Cross(U);           
	vec3 B = A.Cross(C);    
	float magA = sqrt(A[0]*A[0]+A[1]*A[1]+A[2]*A[2]);
	float magB = sqrt(B[0]*B[0]+B[1]*B[1]+B[2]*B[2]);
	float magC = sqrt(C[0]*C[0]+C[1]*C[1]+C[2]*C[2]); 
	float scalerH = magC*tanPhi/magA; 
	float scalerV = magC*tanTheta/magB; 
	vec3 H = scalerH*A; 
	vec3 V = scalerV*B; 

 
	vector<spline> splineSets (2); 
	splineSets[0].first = vec3 (-15.0, -50.0, -15.0); 
	splineSets[0].second = vec3 (10.0, 10.0, 85.0); 
	splineSets[1].first = vec3 (70.0, 20.0, 30.0); 
	splineSets[1].second = vec3 (-20.0, -5.0, 100.0);

	vector<projectline> projectlineSets(2); 
	projectlineSets[0].first = vec2 (0.0, 0.0); 
	projectlineSets[0].second = vec2 (0.0, 0.0); 
	projectlineSets[1].first = vec2 (0.0, 0.0); 
	projectlineSets[1].second = vec2 (0.0, 0.0);

	
	for(int lineNum = 0; lineNum < splineSets.size(); ++lineNum)
	{
		for(int i = 0; i< resoX; ++i)
		{
			cout<<"current pixel:"<<i<<endl; 
			for(int j = 0; j< resoY; ++j)
			{
				float Sx = (float)(1.0*i)/(1.0*resoX); 
				float Sy = (float)(1.0*j)/(1.0*resoY); 
				vec3 P = M+(2*Sx-1)*H + (2*Sy-1)*V; 
				float magPE = sqrt((P[0]-E[0])*(P[0]-E[0])+(P[1]-E[1])*(P[1]-E[1])+(P[2]-E[2])*(P[2]-E[2])); 
				vec3 vect = (P-E)/magPE; 

				float t = 0.0; 
				for(t = 0.0; (t*vect).Length() <magPE; t=t+0.5)
				{
					vec3 R = E+t*vect; 
					vec3 intR = vec3 ((int)(R[0]), (int)(R[1]), (int)(R[2]));

					vec3 intFirst = vec3 ((int) (splineSets[lineNum].first[0]), (int) (splineSets[lineNum].first[1]), (int) (splineSets[lineNum].first[2]));
					vec3 intSecond = vec3 ((int) (splineSets[lineNum].second[0]), (int) (splineSets[lineNum].second[1]), (int) (splineSets[lineNum].second[2]));
					
					if(intR == intFirst)
					{
						projectlineSets[lineNum].first = vec2 (i,j); 
					}

					if(intR == intSecond)
					{
						projectlineSets[lineNum].second = vec2 (i,j); 
					}
			    }
		   }
	   }
	}
	*/
	/*
	cout<<projectlineSets[0].first[0]<<endl;     
	cout<<projectlineSets[0].first[1]<<endl; 
	cout<<projectlineSets[0].second[0]<<endl; 
	cout<<projectlineSets[0].second[1]<<endl; 
	cout<<projectlineSets[1].first[0]<<endl; 
	cout<<projectlineSets[1].first[1]<<endl; 
	cout<<projectlineSets[1].second[0]<<endl; 
	cout<<projectlineSets[1].second[1]<<endl;        
	int n; 
	cin>>n; */ 

	/*
	//background color 
	for(int i = 0; i< resoX; ++i)
	{
		//cout<<"current pixel:"<<i<<endl; 
		for(int j = 0; j< resoY; ++j)
		{
			output(i, resoY-1-j)->Red = 255; 
			output(i, resoY-1-j)->Blue = 255; 
			output(i, resoY-1-j)->Green = 255;
		}
	}


    //digital differential anaylizer algorithm 
	for(int lineNum = 0; lineNum < projectlineSets.size(); ++lineNum)
	{
			int x1 = projectlineSets[lineNum].first[0]; 
		    int y1 = projectlineSets[lineNum].first[1]; 
		    int x2 = projectlineSets[lineNum].second[0]; 
		    int y2 = projectlineSets[lineNum].second[1]; 

			float x = 0.0; 
			float y = 0.0; 
			float xInc = x2 - x1; 
			float yInc = y2 - y1; 
			float Length = 0.0; 

			if((xInc == 0.0)&&(yInc == 0.0))
			{
				output(x1, resoY-1-y1)->Red = 0; 
				output(x1, resoY-1-y1)->Blue = 0; 
				output(x1, resoY-1-y1)->Green = 0;
			}else
			{
				if(abs(yInc)>abs(xInc))
				{
					Length = abs(yInc); 
					xInc = xInc/Length; 
					yInc = 1.0; 
				}else
				{
					Length = abs(xInc); 
					yInc = yInc/Length; 
					xInc = 1.0; 
				}
				x = x1; 
				y = y1; 

				for (int i = 0; i <= (int) (Length+1); ++i)
				{
					output((int)(x+1), (int) (resoY-1-y))->Red = 0; 
					output((int)(x+1), (int) (resoY-1-y))->Blue = 0; 
					output((int)(x+1), (int) (resoY-1-y))->Green = 0;
					x = x+xInc; 
					y = y+yInc; 
				}
			}  
	}   

	output.WriteToFile("StraightLineProjection.bmp");
	*/
}