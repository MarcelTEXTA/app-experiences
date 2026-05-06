#include <wx/wx.h>
#include <wx/textctrl.h>
#include <wx/filedlg.h>
#include <wx/memory.h>

class NotepadApp : public wxApp {
public:
    bool OnInit() override;
};

class NotepadFrame : public wxFrame {
public:
    NotepadFrame();

private:
    void OnNew(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnSave(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);

    void OnUndo(wxCommandEvent& event);
    void OnRedo(wxCommandEvent& event);
    void OnCut(wxCommandEvent& event);
    void OnCopy(wxCommandEvent& event);
    void OnPaste(wxCommandEvent& event);
    void OnDelete(wxCommandEvent& event);
    void OnSelectAll(wxCommandEvent& event);
    void OnFind(wxCommandEvent& event);
    void OnReplace(wxCommandEvent& event);

    void OnAbout(wxCommandEvent& event);

    wxTextCtrl* textCtrl;
};

wxIMPLEMENT_APP(NotepadApp);

bool NotepadApp::OnInit() {
    auto frame = new NotepadFrame();
    frame->Show(true);
    return true;
}

NotepadFrame::NotepadFrame()
    : wxFrame(nullptr, wxID_ANY, "Notepad", wxDefaultPosition, wxSize(800, 600))
{
    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(wxID_NEW, "&New\tCtrl+N");
    fileMenu->Append(wxID_OPEN, "&Open...\tCtrl+O");
    fileMenu->Append(wxID_SAVE, "&Save\tCtrl+S");
    fileMenu->AppendSeparator();
    fileMenu->Append(wxID_EXIT, "E&xit\tAlt+F4");

    wxMenu* editMenu = new wxMenu;
    editMenu->Append(wxID_UNDO, "&Undo\tCtrl+Z");
    editMenu->Append(wxID_REDO, "&Redo\tCtrl+Y");
    editMenu->AppendSeparator();
    editMenu->Append(wxID_CUT, "Cu&t\tCtrl+X");
    editMenu->Append(wxID_COPY, "&Copy\tCtrl+C");
    editMenu->Append(wxID_PASTE, "&Paste\tCtrl+V");
    editMenu->Append(wxID_DELETE, "&Delete\tDel");
    editMenu->AppendSeparator();
    editMenu->Append(wxID_SELECTALL, "Select &All\tCtrl+A");
    editMenu->Append(wxID_FIND, "&Find...\tCtrl+F");
    editMenu->Append(wxID_REPLACE, "&Replace...\tCtrl+H");

    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, "&About\tF1");

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(editMenu, "&Edit");
    menuBar->Append(helpMenu, "&Help");
    SetMenuBar(menuBar);

    textCtrl = new wxTextCtrl(
        this,
        wxID_ANY,
        "",
        wxDefaultPosition,
        wxDefaultSize,
        wxTE_MULTILINE
    );

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(textCtrl, 1, wxEXPAND);
    SetSizer(sizer);

    Bind(wxEVT_MENU, &NotepadFrame::OnNew, this, wxID_NEW);
    Bind(wxEVT_MENU, &NotepadFrame::OnOpen, this, wxID_OPEN);
    Bind(wxEVT_MENU, &NotepadFrame::OnSave, this, wxID_SAVE);
    Bind(wxEVT_MENU, &NotepadFrame::OnExit, this, wxID_EXIT);

    Bind(wxEVT_MENU, &NotepadFrame::OnUndo, this, wxID_UNDO);
    Bind(wxEVT_MENU, &NotepadFrame::OnRedo, this, wxID_REDO);
    Bind(wxEVT_MENU, &NotepadFrame::OnCut, this, wxID_CUT);
    Bind(wxEVT_MENU, &NotepadFrame::OnCopy, this, wxID_COPY);
    Bind(wxEVT_MENU, &NotepadFrame::OnPaste, this, wxID_PASTE);
    Bind(wxEVT_MENU, &NotepadFrame::OnDelete, this, wxID_DELETE);
    Bind(wxEVT_MENU, &NotepadFrame::OnSelectAll, this, wxID_SELECTALL);
    Bind(wxEVT_MENU, &NotepadFrame::OnFind, this, wxID_FIND);
    Bind(wxEVT_MENU, &NotepadFrame::OnReplace, this, wxID_REPLACE);

    Bind(wxEVT_MENU, &NotepadFrame::OnAbout, this, wxID_ABOUT);
}

void NotepadFrame::OnNew(wxCommandEvent& event) {
    textCtrl->Clear();
}

void NotepadFrame::OnOpen(wxCommandEvent& event) {
    wxFileDialog openFileDialog(this, "Open Text File", "", "", "Text files (*.txt)/*.txt|all files (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;
    wxString filePath = openFileDialog.GetPath();
    wxMessageBox("File opened: " + filePath, "Notepad", wxOK | wxICON_INFORMATION);
}

void NotepadFrame::OnSave(wxCommandEvent& event) {
    wxFileDialog saveFileDialog(this, "Save Text File", "", "", "Text files (*.txt)/*.txt|all files (*.*)|*.*", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;
    wxString filePath = saveFileDialog.GetPath();
    wxMessageBox("File saved: " + filePath, "Notepad", wxOK | wxICON_INFORMATION);
}

void NotepadFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}


void NotepadFrame::OnUndo(wxCommandEvent& event) {
    textCtrl->Undo();
}

void NotepadFrame::OnRedo(wxCommandEvent& event) {
    textCtrl->Redo();
}

void NotepadFrame::OnCut(wxCommandEvent& event) {
    textCtrl->Cut();
}

void NotepadFrame::OnCopy(wxCommandEvent& event) {
    textCtrl->Copy();
}

void NotepadFrame::OnPaste(wxCommandEvent& event) {
    textCtrl->Paste();
}

void NotepadFrame::OnDelete(wxCommandEvent& event) {
    textCtrl->RemoveSelection();
}

void NotepadFrame::OnSelectAll(wxCommandEvent& event) {
    textCtrl->SelectAll();
}

void NotepadFrame::OnFind(wxCommandEvent& event) {
    wxMessageBox("Find dialog would appear!", "Notepad", wxOK | wxICON_INFORMATION);
}

void NotepadFrame::OnReplace(wxCommandEvent& event) {
    wxMessageBox("Replace dialog would appear!", "Notepad", wxOK | wxICON_INFORMATION);
}


void NotepadFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Notepad\nVersion 1.0\nCreated with wxWidgets", "About Notepad", wxOK | wxICON_INFORMATION);
}