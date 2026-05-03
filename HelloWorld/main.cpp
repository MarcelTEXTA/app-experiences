#include <wx/wx.h>

class MyApp : public wxApp {
public:
    bool OnInit() override;
};

class MyFrame : public wxFrame {
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "App experiences", wxDefaultPosition, wxSize(800, 600)) {
        new wxStaticText(this, wxID_ANY, "Hello wxWidgets! Welcome!", wxPoint(20, 20));
    }
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}