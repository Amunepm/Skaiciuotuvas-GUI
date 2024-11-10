#include "MainFrame.h"
#include <wx/wx.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>

using namespace std;

// Sitas zenklas "->" turi reiksme norint pasiekti pointerius arba rodykle, pvz cia: choice->Select(0); mes norime pasiekti choice pointeri, kad galetume priskirti jam selecta

MainFrame::MainFrame(const wxString& Skaiciuotuvas): wxFrame(nullptr, wxID_ANY, Skaiciuotuvas) {
	wxPanel* panel = new wxPanel(this); // Si eilute skirta tam, kad mygtukas ir kitos sio frame dalys nebutu per visa ekrana

	//Tekstas

	ekranas = new wxStaticText(panel, wxID_ANY, "0", wxPoint(0, 50),wxSize(800,-1),wxALIGN_CENTER); // Si kodo eilute mums parodo parasyta teksta, programeleje teksto negalima bus redaguoti

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

	nr1->Bind(wxEVT_BUTTON, &MainFrame::OnButton1Clicked, this);
	nr2->Bind(wxEVT_BUTTON, &MainFrame::OnButton2Clicked, this);
	nr3->Bind(wxEVT_BUTTON, &MainFrame::OnButton3Clicked, this);
	nr4->Bind(wxEVT_BUTTON, &MainFrame::OnButton4Clicked, this);
	nr5->Bind(wxEVT_BUTTON, &MainFrame::OnButton5Clicked, this);
	nr6->Bind(wxEVT_BUTTON, &MainFrame::OnButton6Clicked, this);
	nr7->Bind(wxEVT_BUTTON, &MainFrame::OnButton7Clicked, this);
	nr8->Bind(wxEVT_BUTTON, &MainFrame::OnButton8Clicked, this);
	nr9->Bind(wxEVT_BUTTON, &MainFrame::OnButton9Clicked, this);
	nr0->Bind(wxEVT_BUTTON, &MainFrame::OnButton10Clicked, this);
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

// Operatoriu priskirimas

bool Operatorius(char operatorius)
{                                                                                                    
	return(operatorius == '+' || operatorius == '-' || operatorius == 'x' || operatorius == '÷' ||  operatorius == '%');
}

//Eventu voidai su zinute

void MainFrame::OnButton1Clicked(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if (skaicius.rfind("COS(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SIN(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}																																													// Visos sios salygos tikrina ar jau yra parasytas sin,cos,pow,sqrt jei yra, tai tada neleistu daugiau parasyti arba tik po paskutinio operatoriaus
	else if (skaicius.rfind("POW(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SQRT(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("LOG10(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
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
void MainFrame::OnButton2Clicked(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if (skaicius.rfind("COS(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SIN(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("POW(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SQRT(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("LOG10(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
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
void MainFrame::OnButton3Clicked(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if (skaicius.rfind("COS(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SIN(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("POW(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SQRT(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("LOG10(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
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
void MainFrame::OnButton4Clicked(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if (skaicius.rfind("COS(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SIN(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("POW(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SQRT(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("LOG(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("LOG10(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
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
void MainFrame::OnButton5Clicked(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if (skaicius.rfind("COS(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SIN(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("POW(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SQRT(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("LOG10(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
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
void MainFrame::OnButton6Clicked(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if (skaicius.rfind("COS(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SIN(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("POW(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SQRT(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("LOG10(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
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
void MainFrame::OnButton7Clicked(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if (skaicius.rfind("COS(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SIN(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("POW(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SQRT(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("LOG10(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
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
void MainFrame::OnButton8Clicked(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if (skaicius.rfind("COS(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SIN(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("POW(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SQRT(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("LOG10(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
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
void MainFrame::OnButton9Clicked(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if (skaicius.rfind("COS(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SIN(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("POW(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SQRT(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("LOG10(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
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
void MainFrame::OnButton10Clicked(wxCommandEvent& event) {

	int operatoriausPozicija = skaicius.find_last_of("+-x÷");

	if (skaicius.rfind("COS(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SIN(") != string::npos && skaicius.rfind(")") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("POW(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SQRT(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("LOG10(") != string::npos && (operatoriausPozicija == string::npos || operatoriausPozicija < skaicius.rfind(")")))
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
	// Padaryti taip, kad jei prieki yra nulis tai neleistu rasyti po nulio betkoki skaiciu arba nuli nebent tai yra simtas arba po nulio kablelis.
	ekranas->SetLabel(skaicius);
}
void MainFrame::TaskelioMygtukas(wxCommandEvent& event) {
	//Ka reiskia string::npos - Tai yra speciali reikšmė, kurią funkcija grąžina tik tada, kai paieška nesėkminga(neranda ieškomo simbolio).
	
	int PaskutinisOperatorius = skaicius.find_last_of("+-x+"); // Sis kodas mums leis surasti paskutini operatoriu, kuris buvo naudojamas musu skaiciuotuve

	string PakeistinisSkaicius; // Mums sis kintamasis reikalingas tam, kad apsibreztume skaiciu po operatoriaus pvz: 1,2 tada operatorius + ir tada musu pakeistinisskaicius 1,23

	if (skaicius.rfind("COS(") != string::npos && skaicius.rfind(")") != string::npos && (PaskutinisOperatorius == string::npos || PaskutinisOperatorius < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SIN(") != string::npos && skaicius.rfind(")") != string::npos && (PaskutinisOperatorius == string::npos || PaskutinisOperatorius < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("POW(") != string::npos && (PaskutinisOperatorius == string::npos || PaskutinisOperatorius < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("SQRT(") != string::npos && (PaskutinisOperatorius == string::npos || PaskutinisOperatorius < skaicius.rfind(")")))
	{
		return;
	}
	else if (skaicius.rfind("LOG10(") != string::npos && (PaskutinisOperatorius == string::npos || PaskutinisOperatorius < skaicius.rfind(")")))
	{
		return;
	}

	// Ši sąlyga tikrina, ar paskutinis operatorius buvo rastas eilutėje.
	if (PaskutinisOperatorius != string::npos) { // Naudojame !=, nes tai reiškia "operatorius rastas". Jei būtų ==, tai reikštų, kad operatorius nerastas, nes npos žymi "nerasta" reikšmę.

		// Jei operatorius rastas, surandame skaičiaus dalį po paskutinio operatoriaus.
		// Pvz.: eilutėje "1.23 +", operatoriaus "+" pozicija bus 5. 
		// Naudojame PaskutinisOperatorius + 1 tam, kad pradėtume nuo pirmo simbolio po operatoriaus ("+"), t.y. skaičius po jo.
		PakeistinisSkaicius = skaicius.substr(PaskutinisOperatorius + 1);

	}
	else {

		
		PakeistinisSkaicius = skaicius; // Jei operatorius nerastas, tada visą eilutę (skaicius) laikome kaip vieną skaičių. Kadangi nėra operatoriaus, su juo dirbsime kaip su vienu skaičiumi, todėl tikriname, ar jame yra taškas.
	}

	// Ši sąlyga skirta patikrinti, ar dabartiniame skaičiuje po operatoriaus jau yra taškas
	if (PakeistinisSkaicius.find('.') == string::npos) {  // Čia `npos` reiškia, kad paieškos rezultatas - "nerasta", todėl, jei taškas nerastas, sąlyga suveiks
		// Jei taško nėra, leidžiame jį pridėti prie dabartinio skaičiaus
		skaicius += ".";
	}


	ekranas->SetLabel(skaicius);
}
void MainFrame::SudetiesMygtukas(wxCommandEvent& event) {

	if (!skaicius.empty() && Operatorius(skaicius.back())) { // Musu kodas tikrina ar tai yra operatorius ir ar skaiciai nera tusti. Jei tai operatorius neprides daugiau +, jei norim kita operatoriu apkeisti su + tada back pagalba apkeis.
		skaicius.back() = '+';
	}
	else {
		skaicius += "+";
	}

	ekranas->SetLabel(skaicius);
}
void MainFrame::AtimtiesMygtukas(wxCommandEvent& event) {

	if (!skaicius.empty() && Operatorius(skaicius.back())) {
		skaicius.back() = '-';
	}
	else {
		skaicius += "-";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::DaugybosMygtukas(wxCommandEvent& event) {
	if (!skaicius.empty() && Operatorius(skaicius.back())) {
		skaicius.back() = 'x';
	}
	else {
		skaicius += "x";
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::DalybosMygtukas(wxCommandEvent& event) {

	if (!skaicius.empty() && Operatorius(skaicius.back())) {
		skaicius.back() = '÷';
	}
	else {
		skaicius += "÷";
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
		if (i == skaicius.size() || Operatorius(skaicius[i]))
		{
			if (!skaiciusLaikinas.empty())
			{
				if (skaiciusLaikinas.find("SIN(") != string::npos)
				{
					int pradzia = skaiciusLaikinas.find("SIN(") + 4;
					int pabaiga = skaiciusLaikinas.find(")", pradzia);
					string sinArgumentas = skaiciusLaikinas.substr(pradzia, pabaiga - pradzia);
					double SinValue = stod(sinArgumentas);
					rezultatas = sin(SinValue * M_PI / 180);
				}
				else if (skaiciusLaikinas.find("COS(") != string::npos)
				{
					int pradzia = skaiciusLaikinas.find("COS(") + 4;
					int pabaiga = skaiciusLaikinas.find(")", pradzia);
					string cosArgumentas = skaiciusLaikinas.substr(pradzia, pabaiga - pradzia);
					double CosValue = stod(cosArgumentas);
					rezultatas = cos(CosValue * M_PI / 180);
				}
				else if (skaiciusLaikinas.find("SQRT(") != string::npos)
				{
					int pradzia = skaiciusLaikinas.find("SQRT(") + 5;
					int pabaiga = skaiciusLaikinas.find(")", pradzia);
					string sakniesArgumentas = skaiciusLaikinas.substr(pradzia, pabaiga - pradzia);
					double Saknis = stod(sakniesArgumentas);
					rezultatas = sqrt(Saknis);
				}
				else if (skaiciusLaikinas.find("POW(") != string::npos)
				{
					int pradzia = skaiciusLaikinas.find("POW(") + 4;
					int pabaiga = skaiciusLaikinas.find(")", pradzia);
					string KvadratoArgumentas = skaiciusLaikinas.substr(pradzia, pabaiga - pradzia);
					double Kvadratas = stod(KvadratoArgumentas);
					rezultatas = pow(Kvadratas, 2);
				}
				else if (skaiciusLaikinas.find("LOG10(") != string::npos)
				{
					int pradzia = skaiciusLaikinas.find("LOG10(") + 6;
					int pabaiga = skaiciusLaikinas.find(")", pradzia);
					string LogaritmoArgumentas = skaiciusLaikinas.substr(pradzia, pabaiga - pradzia);
					double Logoritmas = stod(LogaritmoArgumentas);
					rezultatas = log10(Logoritmas);
				}
				else
				{
					double skaiciusDabartinis = stod(skaiciusLaikinas);

					
					
					if (paskutinisOperatorius == '+')
					{
						rezultatas += skaiciusDabartinis;
					}
							
					else if (paskutinisOperatorius == '-')
					{
						rezultatas -= skaiciusDabartinis;
					}
							
					else if (paskutinisOperatorius == 'x')
					{
						rezultatas *= skaiciusDabartinis;
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
						rezultatas /= skaiciusDabartinis;
						}
					}
							
					else if (paskutinisOperatorius == '%')
					{
						rezultatas *= skaiciusDabartinis / 100;
					}
							
					
				}

				skaiciusLaikinas = "";
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

void MainFrame::SkaiciausPasalinimoMygtukas(wxCommandEvent& event) {

	if (skaicius.size() > 1) // tikriname ar skaicius nera lygus 0
	{
		skaicius.pop_back(); // Tada saliname ta skaiciu naudodami pop_back - pop_back funkcija pasalina paskutini elementa
	}
	else
	{
		skaicius = "0"; // Si eilute nubrezia jei tik buna vienas skaicius arba nulis. Tarkime jei skaicius bus 5 tada is 5 gausis 0. O jei nulis tada gausis 0
	}
	ekranas->SetLabel(skaicius);
}
void MainFrame::VisosFunkcijosSalinimoMygtukas(wxCommandEvent& event) {
	
	skaicius = "0";
	ekranas->SetLabel(skaicius);
}
void MainFrame::SakniesMygtukas(wxCommandEvent& event)
{

	int PaskutinisOperatorius = skaicius.find_last_of("+-x÷");

	string PakeistinisSkaicius;

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

	int PaskutinisOperatorius = skaicius.find_last_of("+-x÷");

	string PakeistinisSkaicius;

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
void MainFrame::ProcentuMygtukas(wxCommandEvent& event)
{

	if (skaicius.find("%") != string::npos)
	{
		return;
	}

	if (!skaicius.empty() && Operatorius(skaicius.back()))
	{
		skaicius.back() = '%';
	}
	else
	{
		skaicius += "%";
	}

	ekranas->SetLabel(skaicius);
}
void MainFrame::SinusoMygtukas(wxCommandEvent& event)
{

	int PaskutinisOperatorius = skaicius.find_last_of("+-x÷");

	string PakeistinisSkaicius;
	
	if (PaskutinisOperatorius != string::npos) {
		PakeistinisSkaicius = skaicius.substr(PaskutinisOperatorius + 1);
	}
	else {
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

	int PaskutinisOperatorius = skaicius.find_last_of("+-x÷");

	string PakeistinisSkaicius;

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
	int PaskutinisOperatorius = skaicius.find_last_of("+-x÷");

	string PakeistinisSkaicius;

	if (PaskutinisOperatorius != string::npos)
	{
		PakeistinisSkaicius = skaicius.substr(PaskutinisOperatorius + 1);
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
