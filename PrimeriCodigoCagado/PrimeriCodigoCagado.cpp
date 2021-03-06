// PrimeriCodigoCagado.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include "opencv2\opencv.hpp" 
using namespace cv;

Mat canalCor(Mat imagem, int canal);
Mat negativo(Mat imagem);
Mat cinza(Mat imagem);
int main()
{
	Mat imagem = imread("lena.jpg");
	Mat imagemCinza = cinza(imagem);
	//Mat imagemNegativa = negativo(imagem);
	//Mat imagemCanalVermelho = canalCor(imagem, 2);
	//Mat imagemCanalVerde= canalCor(imagem, 1);
	//Mat imagemCanalAzul = canalCor(imagem, 0);
	//imshow("Vermelho", imagemCanalVermelho);
	//imshow("Azul", imagemCanalAzul);
	//imshow("Verde", imagemCanalVerde);
	//imshow("negativo", imagemNegativa);
	imshow("cinza", imagemCinza);
	waitKey(0);
    return 0;
}

Mat canalCor(Mat imagem, int canal)
{
	Mat imagemRetorno = imagem.clone();
	for (int i = 0; i < imagemRetorno.rows; i++)
	{
		for (int j = 0; j < imagemRetorno.cols; j++)
		{
			Vec3b& pixel = imagemRetorno.at<Vec3b>(i, j);
			uchar cor = pixel[canal];
			pixel[2] = cor;
			pixel[1] = cor;
			pixel[0] = cor;

			
		}
	}

	return imagemRetorno;
}

Mat negativo(Mat imagem)
{
	Mat imagemRetorno = imagem.clone();
	for (int i = 0; i < imagemRetorno.rows; i++)
	{
		for (int j = 0; j < imagemRetorno.cols; j++)
		{
			Vec3b& pixel = imagemRetorno.at<Vec3b>(i, j);
			pixel[2] = 255 - pixel[2];
			pixel[1] = 255 - pixel[1];
			pixel[0] = 255 - pixel[0];
		}
	}

	return imagemRetorno;
}

Mat cinza(Mat imagem)
{
	Mat imagemRetorno = imagem.clone();
	for (int i = 0; i < imagemRetorno.rows; i++)
	{
		for (int j = 0; j < imagemRetorno.cols; j++)
		{
			Vec3b& pixel = imagemRetorno.at<Vec3b>(i, j);
			uchar media = (pixel[2] * 0.21 + pixel[1] * 0.72 + pixel[0] * 0.07) / 1;
			pixel[2] = media;
			pixel[1] = media;
			pixel[0] = media;
		}
	}

	return imagemRetorno;
}
