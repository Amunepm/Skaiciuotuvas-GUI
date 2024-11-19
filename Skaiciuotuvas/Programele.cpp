#include "MainVoid.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(Programele); // Sita kodo eilute yra skirta tam, kad parodytu kas valdys programos vieta(siuo momentu tai bus ("Programele"). Be jos programa neveiktu

// Kaip supratau sitas kodas skirtas tam, kad mano programele rodytusi, kai yra paleistas kodas, kad galima butu programele redaguoti
bool Programele::OnInit() { // Be bool funkcijos sia programele nebutu galima atsidaryti, nes negaletume naudoti true arba false. OnInit yra wxwidgets dalis kuri naudojama grafinio lango sukurimui, kai programa yra paleidziama.

	MainFrame* mainFrame = new MainFrame("Skaiciuotuvas"); // Si eilute yra tam, kad programele turetu savo pavadinima ir taip pat, kad sukurtume nauja frame
	mainFrame->SetWindowStyleFlag(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX)); // Sita koda eilute mes paslepiame resize border ir maximize box, kad nebutu galima keisti programos dydzio
	mainFrame->SetClientSize(800, 600); // Padarome programos dydi plotu ir ilgiu(galima koki nori) pirmas skaitmuo yra x, o antras yra y
	mainFrame->Center(); // Si kodo eilute paleis programa per viduri ekrano
	mainFrame->Show(); // Si kodo eilute leidzia programai pasirodyti save, jei nebutu sios eilutes programa tiesiog nepasirodytu
	return true; // Jei atsakymas butu false programa iskarto uzsidarytu, del to paliekame tai true
}
