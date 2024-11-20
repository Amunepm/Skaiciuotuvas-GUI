#include "Programele.h"
#include <wx/wx.h>
class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& Skaiciuotuvas);
private:
	void Nr1(wxCommandEvent& event); // Kad veiktu musu eventas kai paspaudziame mygtuka
	void Nr2(wxCommandEvent& event);
	void Nr3(wxCommandEvent& event);
	void Nr4(wxCommandEvent& event);
	void Nr5(wxCommandEvent& event);
	void Nr6(wxCommandEvent& event);
	void Nr7(wxCommandEvent& event);
	void Nr8(wxCommandEvent& event);
	void Nr9(wxCommandEvent& event);
	void Nr0(wxCommandEvent& event);
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