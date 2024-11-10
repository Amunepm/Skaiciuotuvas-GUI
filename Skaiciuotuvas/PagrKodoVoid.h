#include <wx/wx.h>
#include <wx/frame.h>
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& Skaiciuotuvas);
private:
	void OnButton1Clicked(wxCommandEvent& event); // Kad veiktu musu eventas kai paspaudziame mygtuka
	void OnButton2Clicked(wxCommandEvent& event);
	void OnButton3Clicked(wxCommandEvent& event);
	void OnButton4Clicked(wxCommandEvent& event);
	void OnButton5Clicked(wxCommandEvent& event);
	void OnButton6Clicked(wxCommandEvent& event);
	void OnButton7Clicked(wxCommandEvent& event);
	void OnButton8Clicked(wxCommandEvent& event);
	void OnButton9Clicked(wxCommandEvent& event);
	void OnButton10Clicked(wxCommandEvent& event);
	void TaskelioMygtukas(wxCommandEvent& event);
	void SudetiesMygtukas(wxCommandEvent& event);
	void AtimtiesMygtukas(wxCommandEvent& event);
	void DaugybosMygtukas(wxCommandEvent& event);
	void DalybosMygtukas(wxCommandEvent& event);
	void LyguMygtukas(wxCommandEvent& event);
	void SkaiciausPasalinimoMygtukas(wxCommandEvent& event);
	void VisosFunkcijosSalinimoMygtukas(wxCommandEvent& event);
	void SakniesMygtukas(wxCommandEvent& event);
	void SkaiciausKelimoKvadratuMygtukas(wxCommandEvent& event);
	void ProcentuMygtukas(wxCommandEvent& event);
	void SinusoMygtukas(wxCommandEvent& event);
	void KosinusoMygtukas(wxCommandEvent& event);
	void LogaritmoMygtukas(wxCommandEvent& event);
	wxStaticText* ekranas;
};

