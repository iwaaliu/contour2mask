#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void contour2_mask(const float contourlist[][2], int sizeoflist, bool *mask_img)
{
	int M=256*2;

std::vector<float> x(sizeoflist, 0.0) ; 
std::vector<float> y(sizeoflist, 0.0) ; 

for(int i=0;i<sizeoflist;i++)
{
}

float max_x=*(std::max_element(x.begin(),x.end()));

/*max_y=std::max_element(contourlist, contourlist+sizeoflist);
min_x=std::min_element(contourlist, contourlist+sizeoflist);
min_y=std::min_element(contourlist, contourlist+sizeoflist);*/

//find crossings

for (int i=0;i<M;i++)
{printf("point at %f%f \n",contourlist[i][0],contourlist[i][1]);

}

int iline;
int j=0;
for (int i=0;i<M;i++)
{

}
}

void contour2mask(int numPoints, const float points[], int x_dim, int y_dim, bool* mask) ;
void contour2mask(int numPoints, const float points[][2], int x_dim, int y_dim, bool* mask) ;

#include <stdio.h>
template<class T>
void outputbuffer(const char* fname, const T* buffer, int siz)
{
	FILE* fid = fopen(fname, "w"); 
	fwrite(buffer, sizeof(T),siz, fid);
	fclose(fid); 
	std::cout<<fname<<std::endl;
}


#include <math.h>
#define ROUND(x) (int)((x)+0.5)

int main()
{
const int N=360;
const int M=256;

float contour_list[N*2];


//bool mask_img[M*M],mask_img0[M*M];
//bool mask_img2[M*M],mask_img_diff[M*M];
bool *mask_img = new bool[M*M];
bool *mask_img0 = new bool[M*M];
bool *mask_img2 = new bool[M*M];
bool *mask_img_diff = new bool[M*M];

for(int i=0;i<M*M;i++)
{
	mask_img[i]=false;
	mask_img0[i]=false;
	mask_img2[i]=false;
	mask_img_diff[i]=false;
}

float r=100.0;
float theta;

for(int i=0;i<N;i++)
{
	theta=0.5*3.1415926+(2*3.1415926*float(i))/float(N)+0.000f;
	contour_list[2*i+1]=r*sin(theta)+0.5*M+20*abs(cos(4*theta));
	contour_list[2*i+0]=r*cos(theta)+0.5*M+20*sin(6*theta);
	cout<<contour_list[i+0]<<" "<<contour_list[2*i+1]<<endl;
	int ii = ROUND(contour_list[2*i+0]);
	int jj = ROUND(contour_list[2*i+1]);
	mask_img0[ii+jj*M]=true;
}
outputbuffer("output_masked_0.dat", &(mask_img0[0]), M*M);

/*contour_list[0][0]=10;
contour_list[0][1]=10;

contour_list[1][0]=10;
contour_list[1][1]=101;
contour_list[2][0]=101;
contour_list[2][1]=101;
contour_list[3][0]=101;
contour_list[3][1]=10;*/



contour2mask(N, contour_list, M, M, &(mask_img[0]));

//--//contour2mask(contour_list, N, &mask_img[0]);
//void contour2mask(int numPoints, const float** points, int x_dim, int y_dim, bool* mask) 
outputbuffer("output_masked.dat", &(mask_img[0]), M*M);

for(int i=0;i<N;i++)
{
	theta=(2*3.1415926*float(i))/float(N);
	contour_list[2*i+0]=r*sin(theta)+0.5*M+20*abs(cos(4*theta))-10;
	if(abs(theta-0.5*3.14159)<1) contour_list[2*i+0]=r*sin(theta)+0.5*M+20*abs(cos(4*theta))-0;
	contour_list[2*i+1]=r*cos(theta)+0.5*M+20*sin(6*theta);
}

contour2mask(N, contour_list, M, M, &(mask_img2[0]));

outputbuffer("output_masked2.dat", &(mask_img2[0]), M*M);
for(int i=0;i<M*M;i++){
	mask_img_diff[i]=mask_img[i]^mask_img2[i];
}
outputbuffer("output_masked_diff.dat", &(mask_img_diff[0]), M*M);

cin.get();
return 0;
}

