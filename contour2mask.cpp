//contour2mask
//Weiguo Lu, 12/02/2015
//last updated by iwaa 12/02/2015
#include <vector>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <iostream>
#define ROUND(x) (int)((x)+0.5)
using std::vector; 
static void calc_intersection(float x0, float y0, float x1, float y1, vector< vector<float> >& list)
{
	int list_size = list.size();

	if(ROUND(y1)==ROUND(y0))
	{
		int y = ROUND(y0);
		y = std::max(y,0);
		y = std::min(y,list_size);
		list[y].push_back(x0);
		list[y].push_back(x1);
		return;
	}

	float slope = (x1-x0)/(y1-y0); 
	int k0 = std::max(ROUND(std::min(y0, y1)),0); 

	int k1 = std::min(ROUND(std::max(y0, y1)),list_size); 

	for (int y=k0; y<k1; y++)
	{
		float x = x0+slope*(y-y0); 
		list[y].push_back(x); 
	}
}


//note mask should be initilized before use 
void contour2mask(int numPoints, const float points[], int x_dim, int y_dim, bool* mask) 
{
	vector< vector<float> > list(y_dim); 
	for (int m=0; m<numPoints; m++)
	{
		//const float* p0 = points[m]; 
		//const float* p1 = points[(m+1)%numPoints]; 
		const float* p0 = &(points[2*m]); 
		const float* p1 = &(points[(2*(m+1))%(2*numPoints)]); 

		calc_intersection(p0[0], p0[1], p1[0], p1[1], list);
	}

	for (int y=0; y<y_dim; y++)
	{
		int length = list[y].size(); 
		if (length<=0) continue; 
	//	if((length%2)) std::cout<<"line "<< y << " has size " << length<<std::endl;
#ifdef _DEBUG
		//assert(!(length%2));
#endif
		std::sort(list[y].begin(), list[y].end()); 
	}

	for (int y=0; y<y_dim; y++) 
	{
		int M = list[y].size(); 
		if (M<=0) continue; 

		bool* data = mask + y*x_dim; 
		const float* x= &(list[y][0]); 
		for (int m=0; m<M; m+=2) 
		{
			int start = ROUND(x[m]);
			int end   = ROUND(x[m+1]);
	//		std::cout<<y<<' '<<M <<" Start: "<< start<<" End: "<<end<<std::endl;
			if (start<0) start = 0; 
			if (end>y_dim-1) end = y_dim-1; 

			for (int i=start; i<=end; i++)
				data[i] = true; 
		}; 	
	}
}  

//note mask should be initilized before use 
void contour2mask(int numPoints, const float points[][2], int x_dim, int y_dim, bool* mask) 
{
	vector< vector<float> > list(y_dim); 
	for (int m=0; m<numPoints; m++)
	{
		const float* p0 = points[m]; 
		const float* p1 = points[(m+1)%numPoints]; 
		calc_intersection(p0[0], p0[1], p1[0], p1[1], list);
	}

	for (int y=0; y<y_dim; y++)
	{
		int length = list[y].size(); 
		if (length<=0) continue; 
	//	if((length%2)) std::cout<<"line "<< y << " has size " << length<<std::endl;
#ifdef _DEBUG
		//assert(!(length%2));
#endif
		std::sort(list[y].begin(), list[y].end()); 
	}

	for (int y=0; y<y_dim; y++) 
	{
		int M = list[y].size(); 
		if (M<=0) continue; 

		bool* data = mask + y*x_dim; 
		const float* x= &(list[y][0]); 
		for (int m=0; m<M; m+=2) 
		{
			int start = ROUND(x[m]);
			int end   = ROUND(x[m+1]);
	//		std::cout<<y<<' '<<M <<" Start: "<< start<<" End: "<<end<<std::endl;
			if (start<0) start = 0; 
			if (end>y_dim-1) end = y_dim-1; 

			for (int i=start; i<=end; i++)
				data[i] = true; 
		}; 	
	}
}  