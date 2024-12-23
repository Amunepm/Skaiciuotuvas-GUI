﻿#include "Programele.h"
#include "MainVoid.h"
#include <wx/wx.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

MainFrame::MainFrame(const wxString& Skaiciuotuvas): wxFrame(nullptr, wxID_ANY, Skaiciuotuvas) {
	wxPanel* panel = new wxPanel(this);

	//Tekstas

	ekranas = new wxStaticText(panel, wxID_ANY,"0", wxPoint(0, 50), wxSize(800, -1), wxALIGN_CENTER); // Si kodo eilute mums parodo parasyta teksta, programeleje teksto negalima bus redaguoti

	//Ekrano pagrazinimas skirtas tekstui
	
	wxFont font(24, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);  // Pakeiciame i Arial Unicode MS
	ekranas->SetFont(font);
	ekranas->SetForegroundColour(*wxBLACK);

	//Mygtukai

	wxButton* nr1 = new wxButton(panel, wxID_ANY, "1", wxPoint(0,460),wxSize(200,70)); // Si eilute kodo skirta tam, kad sukurtume nauja mygtuka

	wxButton* nr2 = new wxButton(panel, wxID_ANY, "2", wxPoint(200, 460), wxSize(200, 70));

	wxButton* nr3 = new wxButton(panel, wxID_ANY, "3", wxPoint(400,460), wxSize(200, 70));

	wxButton* nr4 = new wxButton(panel, wxID_ANY, "4", wxPoint(0, 390), wxSize(200, 70));

	wxButton* nr5 = new wxButton(panel, wxID_ANY, "5", wxPoint(200, 390), wxSize(200, 70));

	wxButton* nr6 = new wxButton(panel, wxID_ANY, "6", wxPoint(400, 390), wxSize(200, 70));

	wxButton* nr7 = new wxButton(panel, wxID_ANY, "7", wxPoint(0, 320), wxSize(200, 70));

	wxButton* nr8 = new wxButton(panel, wxID_ANY, "8", wxPoint(200, 320), wxSize(200, 70));

	wxButton* nr9 = new wxButton(panel, wxID_ANY, "9", wxPoint(400, 320), wxSize(200, 70));

	wxButton* nr0 = new wxButton(panel, wxID_ANY, "0", wxPoint(200, 530), wxSize(200, 70));

	wxButton* sudetis = new wxButton(panel, wxID_ANY, "+", wxPoint(600, 460), wxSize(200, 70));

	wxButton* atimtis = new wxButton(panel, wxID_ANY, "-", wxPoint(600, 390), wxSize(200, 70));
	
	wxButton* daugyba = new wxButton(panel, wxID_ANY, "x", wxPoint(600, 320), wxSize(200, 70));

	wxButton* dalyba = new wxButton(panel, wxID_ANY, "÷", wxPoint(600, 250), wxSize(200, 70));

	wxButton* kvad_saknis = new wxButton(panel, wxID_ANY, wxString::Format("%c", 0x221A) + "x", wxPoint(400, 250), wxSize(200, 70)); // wxString::Format("%c", 0x221A) + "a" si eilute skirta, kad paimtume unicode numeri ir atvaizduotume simboli. "%c" reiskia char ir kad atvaizduos viena simboli. + "x" reiskia, kad mes prie saknies pridesime raide x

	wxButton* Skc_kvad = new wxButton(panel, wxID_ANY, wxString::Format("x%c", 0x00B2), wxPoint(200, 250), wxSize(200, 70)); // "x%c" reiskia, kad pradzioje bus raide "x" ir poto kvadrato zenklas

	wxButton* skaiciaus_salinimas = new wxButton(panel, wxID_ANY, wxString::Format("%c", 0x232B), wxPoint(600, 180), wxSize(200, 70));

	wxButton* visos_funkcijos_istrinimas = new wxButton(panel, wxID_ANY, "C", wxPoint(400, 180), wxSize(200, 70));

	wxButton* lygu = new wxButton(panel, wxID_ANY, "=", wxPoint(600, 530), wxSize(200, 70));
	
	wxButton* taskelis = new wxButton(panel, wxID_ANY, ".", wxPoint(400, 530), wxSize(200, 70));

	wxButton* procentai = new wxButton(panel, wxID_ANY, "%", wxPoint(0, 250), wxSize(200, 70));

	wxButton* kosinusas = new wxButton(panel, wxID_ANY, "COS", wxPoint(0, 180), wxSize(200, 70));

	wxButton* sinusas = new wxButton(panel, wxID_ANY, "SIN", wxPoint(200, 180), wxSize(200, 70));

	wxButton* logaritmas = new wxButton(panel, wxID_ANY, "LOG10", wxPoint(0, 530), wxSize(200, 70));

	//Mygtuku fontai

	nr1->SetFont(font);
	nr2->SetFont(font);
	nr3->SetFont(font);
	nr4->SetFont(font);
	nr5->SetFont(font);
	nr6->SetFont(font);
	nr7->SetFont(font);
	nr8->SetFont(font);
	nr9->SetFont(font);
	nr0->SetFont(font);

	sudetis->SetFont(font);
	atimtis->SetFont(font);
	daugyba->SetFont(font);
	dalyba->SetFont(font);
	kvad_saknis->SetFont(font);
	Skc_kvad->SetFont(font);
	skaiciaus_salinimas->SetFont(font);
	visos_funkcijos_istrinimas->SetFont(font);
	lygu->SetFont(font);
	taskelis->SetFont(font);
	procentai->SetFont(font);
	kosinusas->SetFont(font);
	sinusas->SetFont(font);
	logaritmas->SetFont(font);

	//Eventu bindai

	nr1->Bind(wxEVT_BUTTON, &MainFrame::Nr1, this);
	nr2->Bind(wxEVT_BUTTON, &MainFrame::Nr2, this);
	nr3->Bind(wxEVT_BUTTON, &MainFrame::Nr3, this);
	nr4->Bind(wxEVT_BUTTON, &MainFrame::Nr4, this);
	nr5->Bind(wxEVT_BUTTON, &MainFrame::Nr5, this);
	nr6->Bind(wxEVT_BUTTON, &MainFrame::Nr6, this);
	nr7->Bind(wxEVT_BUTTON, &MainFrame::Nr7, this);
	nr8->Bind(wxEVT_BUTTON, &MainFrame::Nr8, this);
	nr9->Bind(wxEVT_BUTTON, &MainFrame::Nr9, this);
	nr0->Bind(wxEVT_BUTTON, &MainFrame::Nr0, this);
	taskelis->Bind(wxEVT_BUTTON, &MainFrame::TaskelioMygtukas, this);
	sudetis->Bind(wxEVT_BUTTON, &MainFrame::SudetiesMygtukas, this);
	atimtis->Bind(wxEVT_BUTTON, &MainFrame::AtimtiesMygtukas, this);
	daugyba->Bind(wxEVT_BUTTON, &MainFrame::DaugybosMygtukas, this);
	dalyba->Bind(wxEVT_BUTTON, &MainFrame::DalybosMygtukas, this);
	lygu->Bind(wxEVT_BUTTON, &MainFrame::LyguMygtukas, this);
	skaiciaus_salinimas->Bind(wxEVT_BUTTON, &MainFrame::SkaiciausPasalinimoMygtukas, this);
	visos_funkcijos_istrinimas->Bind(wxEVT_BUTTON, &MainFrame::VisosFunkcijosSalinimoMygtukas, this);
	kvad_saknis->Bind(wxEVT_BUTTON, &MainFrame::SakniesMygtukas, this);
	Skc_kvad->Bind(wxEVT_BUTTON, &MainFrame::SkaiciausKelimoKvadratuMygtukas, this);
	procentai->Bind(wxEVT_BUTTON, &MainFrame::ProcentuMygtukas, this);
	kosinusas->Bind(wxEVT_BUTTON, &MainFrame::KosinusoMygtukas, this);
	sinusas->Bind(wxEVT_BUTTON, &MainFrame::SinusoMygtukas, this);
	logaritmas->Bind(wxEVT_BUTTON, &MainFrame::LogaritmoMygtukas, this);

}
//Kintamuju apsibrezimas

string skaicius = "0";

//Eventu voidai su zinute

void MainFrame::Nr1(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷%");

	if ((skaicius.find("COS(") != string::npos || skaicius.find("SIN(") != string::npos || skaicius.find("POW(") != string::npos || skaicius.find("SQRT(") != string::npos || skaicius.find("LOG10(") != string::npos) && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	
	if (operatoriausPozicija != string::npos && skaicius.substr(operatoriausPozicija + 1) == "0") // Si salyga tikrina ar po paskutinio operatoriaus buvo nulis. Si salyga skirta tam, kad neleistu prideti po nulio daugiau skaiciu. Pvz: 1+012. Tai kai mes paspausime po operatoriaus nuli, neleis mums prideti daugiau nei nuliu prie nulio ir skaiciu prie nulio, vietoj to tiesiog apkeis ta nuliuka su kitu skaiciumi
	{
		skaicius.pop_back(); // Jei salyga ir teisinga tada pasalins nuliuka ir parasys musu paspausta skaiciu
	}
	
	if (skaicius == "0") // Patikriname, ar ekrane rodomas skaičius yra lygus "0".
	{
		skaicius = "1";  // Jei rodomas "0", pakeičiame jį į "1" (kadangi negalime palikti pradinio nulio prieš kitą skaičių).
	}
	else 
	{
		skaicius += "1";  // Jei ekrane rodomas ne "0", pridedame skaičių "1" prie jau esamos reikšmės.
	}

	ekranas->SetLabel(skaicius);  // Atnaujiname ekraną (wxStaticText) su naujai suformuotu tekstu (skaičiumi).
}
void MainFrame::Nr2(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if ((skaicius.find("COS(") != string::npos || skaicius.find("SIN(") != string::npos || skaicius.find("POW(") != string::npos || skaicius.find("SQRT(") != string::npos || skaicius.find("LOG10(") != string::npos) && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}

	if(operatoriausPozicija != string::npos && skaicius.substr(operatoriausPozicija + 1) == "0")
	{
		skaicius.pop_back();
	}

	if (skaicius == "0") {
		skaicius = "2";
	}
	else
	{
		skaicius += "2";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::Nr3(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if ((skaicius.find("COS(") != string::npos || skaicius.find("SIN(") != string::npos || skaicius.find("POW(") != string::npos || skaicius.find("SQRT(") != string::npos || skaicius.find("LOG10(") != string::npos) && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}

	if (operatoriausPozicija != string::npos && skaicius.substr(operatoriausPozicija + 1) == "0")
	{
		skaicius.pop_back();
	}

	if (skaicius == "0") {
		skaicius = "3";
	}
	else
	{
		skaicius += "3";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::Nr4(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if ((skaicius.find("COS(") != string::npos || skaicius.find("SIN(") != string::npos || skaicius.find("POW(") != string::npos || skaicius.find("SQRT(") != string::npos || skaicius.find("LOG10(") != string::npos) && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}

	if (operatoriausPozicija != string::npos && skaicius.substr(operatoriausPozicija + 1) == "0")
	{
		skaicius.pop_back();
	}

	if (skaicius == "0") {
		skaicius = "4";
	}
	else
	{
		skaicius += "4";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::Nr5(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if ((skaicius.find("COS(") != string::npos || skaicius.find("SIN(") != string::npos || skaicius.find("POW(") != string::npos || skaicius.find("SQRT(") != string::npos || skaicius.find("LOG10(") != string::npos) && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}

	if (operatoriausPozicija != string::npos && skaicius.substr(operatoriausPozicija + 1) == "0")
	{
		skaicius.pop_back();
	}

	if (skaicius == "0") {
		skaicius = "5";
	}
	else
	{
		skaicius += "5";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::Nr6(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if ((skaicius.find("COS(") != string::npos || skaicius.find("SIN(") != string::npos || skaicius.find("POW(") != string::npos || skaicius.find("SQRT(") != string::npos || skaicius.find("LOG10(") != string::npos) && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}

	if (operatoriausPozicija != string::npos && skaicius.substr(operatoriausPozicija + 1) == "0")
	{
		skaicius.pop_back();
	}

	if (skaicius == "0") {
		skaicius = "6";
	}
	else
	{
		skaicius += "6";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::Nr7(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if ((skaicius.find("COS(") != string::npos || skaicius.find("SIN(") != string::npos || skaicius.find("POW(") != string::npos || skaicius.find("SQRT(") != string::npos || skaicius.find("LOG10(") != string::npos) && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}

	if (operatoriausPozicija != string::npos && skaicius.substr(operatoriausPozicija + 1) == "0")
	{
		skaicius.pop_back();
	}

	if (skaicius == "0") {
		skaicius = "7";
	}
	else
	{
		skaicius += "7";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::Nr8(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if ((skaicius.find("COS(") != string::npos || skaicius.find("SIN(") != string::npos || skaicius.find("POW(") != string::npos || skaicius.find("SQRT(") != string::npos || skaicius.find("LOG10(") != string::npos) && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}

	if (operatoriausPozicija != string::npos && skaicius.substr(operatoriausPozicija + 1) == "0")
	{
		skaicius.pop_back();
	}

	if (skaicius == "0") {
		skaicius = "8";
	}
	else
	{
		skaicius += "8";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::Nr9(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if ((skaicius.find("COS(") != string::npos || skaicius.find("SIN(") != string::npos || skaicius.find("POW(") != string::npos || skaicius.find("SQRT(") != string::npos || skaicius.find("LOG10(") != string::npos) && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}

	if (operatoriausPozicija != string::npos && skaicius.substr(operatoriausPozicija + 1) == "0")
	{
		skaicius.pop_back();
	}

	if (skaicius == "0") {
		skaicius = "9";
	}
	else
	{
		skaicius += "9";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::Nr0(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if ((skaicius.find("COS(") != string::npos || skaicius.find("SIN(") != string::npos || skaicius.find("POW(") != string::npos || skaicius.find("SQRT(") != string::npos || skaicius.find("LOG10(") != string::npos) && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}

	if (operatoriausPozicija != string::npos && skaicius.substr(operatoriausPozicija + 1) == "0")
	{
		skaicius.pop_back();
	}

	if (skaicius == "0") {
		skaicius = "0";
	}
	else
	{
		skaicius += "0";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::SudetiesMygtukas(wxCommandEvent& event) {
	
	int operatoriausPozicija = skaicius.find_last_of("+-x÷%");
	
	if (operatoriausPozicija != string::npos && operatoriausPozicija == skaicius.size() - 1) { 
		skaicius.back() = '+';
	}
	else {
		skaicius += "+";
	}

	ekranas->SetLabel(skaicius);
}
void MainFrame::AtimtiesMygtukas(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷%");

	if (operatoriausPozicija != string::npos && operatoriausPozicija == skaicius.size() - 1) {
		skaicius.back() = '-';
	}
	else {
		skaicius += "-";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::DaugybosMygtukas(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷%");

	if (operatoriausPozicija != string::npos && operatoriausPozicija == skaicius.size() - 1) {
		skaicius.back() = 'x';
	}
	else {
		skaicius += "x";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::DalybosMygtukas(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷%");

	if (operatoriausPozicija != string::npos && operatoriausPozicija == skaicius.size() - 1) {
		skaicius.back() = '÷';
	}
	else {
		skaicius += "÷";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::ProcentuMygtukas(wxCommandEvent& event)
{
	int operatoriausPozicija = skaicius.find_last_of("+-x÷%");

	if (skaicius.find("%") != string::npos)
	{
		return;
	}

	

	if (operatoriausPozicija != string::npos && operatoriausPozicija == skaicius.size() - 1) {
		skaicius.back() = '%';
	}
	else {
		skaicius += "%";
	}

	ekranas->SetLabel(skaicius);
}
void MainFrame::SkaiciausPasalinimoMygtukas(wxCommandEvent& event) {

	if (skaicius.size() > 1)
	{
		skaicius.pop_back();
	}
	else
	{
		skaicius = "0";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::VisosFunkcijosSalinimoMygtukas(wxCommandEvent& event) {

	skaicius = "0";
	ekranas->SetLabel(skaicius);
}
void MainFrame::SakniesMygtukas(wxCommandEvent& event)
{

	int PaskutinisOperatorius = skaicius.find_last_of("+-x÷%");

	string PakeistinisSkaicius;

	if (PaskutinisOperatorius != string::npos)
	{
		PakeistinisSkaicius = skaicius.substr(PaskutinisOperatorius + 1);

		if (PakeistinisSkaicius.empty() || !isdigit(PakeistinisSkaicius.back()))
		{
			return;
		}
	}

	if (PaskutinisOperatorius != string::npos)
	{
		PakeistinisSkaicius = skaicius.substr(PaskutinisOperatorius + 1);
	}
	else
	{
		PakeistinisSkaicius = skaicius;
	}

	if (PakeistinisSkaicius.find("SQRT(") == string::npos)
	{
		skaicius = skaicius.substr(0, PaskutinisOperatorius + 1) + "SQRT(" + PakeistinisSkaicius + ")";
	}

	ekranas->SetLabel(skaicius);

}
void MainFrame::SkaiciausKelimoKvadratuMygtukas(wxCommandEvent& event)
{

	int PaskutinisOperatorius = skaicius.find_last_of("+-x÷%");

	string PakeistinisSkaicius;

	if (PaskutinisOperatorius != string::npos)
	{
		PakeistinisSkaicius = skaicius.substr(PaskutinisOperatorius + 1);

		if (PakeistinisSkaicius.empty() || !isdigit(PakeistinisSkaicius.back()))
		{
			return;
		}
	}

	if (PaskutinisOperatorius != string::npos)
	{
		PakeistinisSkaicius = skaicius.substr(PaskutinisOperatorius + 1);
	}
	else
	{
		PakeistinisSkaicius = skaicius;
	}

	if (PakeistinisSkaicius.find("POW(") == string::npos)
	{
		skaicius = skaicius.substr(0, PaskutinisOperatorius + 1) + "POW(" + PakeistinisSkaicius + ")";
	}

	ekranas->SetLabel(skaicius);

}
void MainFrame::SinusoMygtukas(wxCommandEvent& event)
{

	int PaskutinisOperatorius = skaicius.find_last_of("+-x÷%");

	string PakeistinisSkaicius;

	if (PaskutinisOperatorius != string::npos)
	{
		PakeistinisSkaicius = skaicius.substr(PaskutinisOperatorius + 1);

		if (PakeistinisSkaicius.empty() || !isdigit(PakeistinisSkaicius.back()))
		{
			return;
		}
	}
	else 
	{
		PakeistinisSkaicius = skaicius;
	}

	if (PakeistinisSkaicius.find("SIN(") == string::npos)
	{
		skaicius = skaicius.substr(0, PaskutinisOperatorius + 1) + "SIN(" + PakeistinisSkaicius + ")";
		// Ši eilutė paima išraišką iki paskutinio operatoriaus (įskaitant operatorių), o tada prideda "sin()" funkciją tam skaičiui, kuris yra po operatoriaus. 
		// Jei operatoriaus nėra, sin() taikoma visam esamam skaičiui.
	}

	ekranas->SetLabel(skaicius);
}
void MainFrame::KosinusoMygtukas(wxCommandEvent& event)
{

	int PaskutinisOperatorius = skaicius.find_last_of("+-x÷%");

	string PakeistinisSkaicius;
	
	if (PaskutinisOperatorius != string::npos)
	{
		PakeistinisSkaicius = skaicius.substr(PaskutinisOperatorius + 1);

		if (PakeistinisSkaicius.empty() || !isdigit(PakeistinisSkaicius.back()))
		{
			return;
		}
	}

	if (PaskutinisOperatorius != string::npos)
	{
		PakeistinisSkaicius = skaicius.substr(PaskutinisOperatorius + 1);
	}
	else
	{
		PakeistinisSkaicius = skaicius;
	}

	if (PakeistinisSkaicius.find("COS(") == string::npos)
	{
		skaicius = skaicius.substr(0, PaskutinisOperatorius + 1) + "COS(" + PakeistinisSkaicius + ")";
	}

	ekranas->SetLabel(skaicius);
}
void MainFrame::LogaritmoMygtukas(wxCommandEvent& event)
{
	int PaskutinisOperatorius = skaicius.find_last_of("+-x÷%");

	string PakeistinisSkaicius;

	if (PaskutinisOperatorius != string::npos)
	{
		PakeistinisSkaicius = skaicius.substr(PaskutinisOperatorius + 1);

		if (PakeistinisSkaicius.empty() || !isdigit(PakeistinisSkaicius.back()))
		{
			return;
		}
	}

	else
	{
		PakeistinisSkaicius = skaicius;
	}

	if (PakeistinisSkaicius.find("LOG10(") == string::npos)
	{
		skaicius = skaicius.substr(0, PaskutinisOperatorius + 1) + "LOG10(" + PakeistinisSkaicius + ")";
	}

	ekranas->SetLabel(skaicius);
}
void MainFrame::TaskelioMygtukas(wxCommandEvent& event) {
	//Ka reiskia string::npos - Tai yra speciali reikšmė, kurią funkcija grąžina tik tada, kai paieška nesėkminga(neranda ieškomo simbolio).
	
	int PaskutinisOperatorius = skaicius.find_last_of("+-x÷%"); // Sis kodas mums leis surasti paskutini operatoriu, kuris buvo naudojamas musu skaiciuotuve

	string PakeistinisSkaicius; // Mums sis kintamasis reikalingas tam, kad apsibreztume skaiciu po operatoriaus pvz: 1,2 tada operatorius + ir tada musu pakeistinisskaicius 1,23

	if ((skaicius.find("COS(") != string::npos || skaicius.find("SIN(") != string::npos || skaicius.find("POW(") != string::npos || skaicius.find("SQRT(") != string::npos || skaicius.find("LOG10(") != string::npos) && (PaskutinisOperatorius == string::npos || PaskutinisOperatorius < skaicius.rfind(")")))
	{
		return;
	}
	
	if (PaskutinisOperatorius != string::npos)
	{
		PakeistinisSkaicius = skaicius.substr(PaskutinisOperatorius + 1);

		if (PakeistinisSkaicius.empty() || !isdigit(PakeistinisSkaicius.back()))
		{
			return;
		}
	}
	else 
	{


		PakeistinisSkaicius = skaicius; // Jei operatorius nerastas, tada visą eilutę (skaicius) laikome kaip vieną skaičių. Kadangi nėra operatoriaus, su juo dirbsime kaip su vienu skaičiumi, todėl tikriname, ar jame yra taškas.
	}
	if (PakeistinisSkaicius.find('.') == string::npos) {  // Čia `npos` reiškia, kad paieškos rezultatas - "nerasta", todėl, jei taškas nerastas, sąlyga suveiks
		//Jei taško nėra, leidžiame jį pridėti prie dabartinio skaičiaus
		skaicius += ".";
	}

	ekranas->SetLabel(skaicius);
}
void MainFrame::LyguMygtukas(wxCommandEvent& event)
{
	long double rezultatas = 0.0;
	string skaiciusLaikinas = "";
	char paskutinisOperatorius = '+';

	for (int i = 0; i <= skaicius.size(); i++)
	{
		if (i == skaicius.size() || string("+-x÷%").find(skaicius[i]) != string::npos)
		{
			if (!skaiciusLaikinas.empty())
			{

				double LaikinasRezultatas = 0.0;

				if (skaiciusLaikinas.find("SIN(") != string::npos)
				{
					int pradzia = skaiciusLaikinas.find("SIN(") + 4;
					int pabaiga = skaiciusLaikinas.find(")", pradzia);
					string sinArgumentas = skaiciusLaikinas.substr(pradzia, pabaiga - pradzia);
					double Sin = stod(sinArgumentas);
					LaikinasRezultatas = sin(Sin * M_PI / 180);
				}
				else if (skaiciusLaikinas.find("COS(") != string::npos)
				{
					int pradzia = skaiciusLaikinas.find("COS(") + 4;
					int pabaiga = skaiciusLaikinas.find(")", pradzia);
					string cosArgumentas = skaiciusLaikinas.substr(pradzia, pabaiga - pradzia);
					double Cos = stod(cosArgumentas);
					LaikinasRezultatas = cos(Cos * M_PI / 180);
				}
				else if (skaiciusLaikinas.find("SQRT(") != string::npos)
				{
					int pradzia = skaiciusLaikinas.find("SQRT(") + 5;
					int pabaiga = skaiciusLaikinas.find(")", pradzia);
					string sakniesArgumentas = skaiciusLaikinas.substr(pradzia, pabaiga - pradzia);
					double Saknis = stod(sakniesArgumentas);
					LaikinasRezultatas = sqrt(Saknis);
				}
				else if (skaiciusLaikinas.find("POW(") != string::npos)
				{
					int pradzia = skaiciusLaikinas.find("POW(") + 4;
					int pabaiga = skaiciusLaikinas.find(")", pradzia);
					string KvadratoArgumentas = skaiciusLaikinas.substr(pradzia, pabaiga - pradzia);
					double Kvadratas = stod(KvadratoArgumentas);
					LaikinasRezultatas = pow(Kvadratas, 2);
				}
				else if (skaiciusLaikinas.find("LOG10(") != string::npos)
				{
					if (skaiciusLaikinas.find("LOG10(0)") != string::npos)
					{
						wxMessageBox("Nulis negali buti logaritme!");
						LaikinasRezultatas = 0;
					}
					else
					{
						int pradzia = skaiciusLaikinas.find("LOG10(") + 6;
						int pabaiga = skaiciusLaikinas.find(")", pradzia);
						string LogaritmoArgumentas = skaiciusLaikinas.substr(pradzia, pabaiga - pradzia);
						double Logoritmas = stod(LogaritmoArgumentas);
						LaikinasRezultatas = log10(Logoritmas);
					}
				}
				else
				{
					LaikinasRezultatas = stod(skaiciusLaikinas);
				}

					if (paskutinisOperatorius == '+')
					{
						rezultatas += LaikinasRezultatas;
					}
							
					else if (paskutinisOperatorius == '-')
					{
						rezultatas -= LaikinasRezultatas;
					}
							
					else if (paskutinisOperatorius == 'x')
					{
						rezultatas *= LaikinasRezultatas;
					}
							
					else if (paskutinisOperatorius == '÷')
					{
						if (skaiciusLaikinas == "0") // Sukuriame salyga, kuri patikrina ar musu skaicius po operatoriaus yra nulis
						{
							wxMessageBox("Skaiciu negalima dalinti is nulio!"); // Jei salyga is tikriju yra teisinga tada perduodame zinute
							rezultatas = 0; // Jei salyga teisinga prilyginam rezultata i nuli, kad galima butu is naujo ivesti skaicius
						}
						else // Jei salyga neteisinga darbas tesiasi toliau.
						{
						rezultatas /= LaikinasRezultatas;
						}
					}
							
					else if (paskutinisOperatorius == '%')
					{
						rezultatas *= LaikinasRezultatas / 100;
					}
							

					skaiciusLaikinas.clear();
			}

			if (i < skaicius.size())
			{
				paskutinisOperatorius = skaicius[i];
			}
		}
		else
		{
			skaiciusLaikinas += skaicius[i];
		}
	}

	stringstream sstream;
	sstream << defaultfloat << rezultatas;
	string atsakymas = sstream.str();
	skaicius = atsakymas;
	ekranas->SetLabel(skaicius);  // Atnaujiname ekraną su rezultatu
}
