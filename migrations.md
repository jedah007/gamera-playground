# Migration

## Migration Guide

Link: [Migration-Guide](https://www.wxpython.org/Phoenix/docs/html/MigrationGuide.html)

### Zutreffende Abschnitte

- Font, Pen and Brush Styles
- Static Methods
- wx.Image and Python Buffer Objects ??
- wx.DropSource
- The wxversion module

## Classic vs Phoenix

Link: [Classic-vs-Phoenix](https://www.wxpython.org/Phoenix/docs/html/classic_vs_phoenix.html#classic-vs-phoenix)

### Zutreffende Modifikationen

Functions and Classes Modifications

- BitmapFrom[Image/Icon]
  - Image: 
    - *gamera_icons.py* muss neu generiert werden
    - `BitmapFromImage(Image)` -> `Bitmap(Image)` (Funktion existiert nicht mehr - auch nicht deprecated!)
    - TODO (inkl. Code-Generierung anpassen!)
  - Icon: [Conversion](https://wiki.wxpython.org/WorkingWithImages#Conversions_Between_wx.Image.2C_wx.Bitmap.2C_wx.Cursor.2C_wx.Icon_and_String_Data)
- CustomDataFormat
- Empty[Bitmap/Image]
  - `EmptyBitmap(...)` -> `Bitmap(...)`
  - `EmptyImage(...)` -> `Image(...)`
- IconFromBitmap
  - `IconFromBitmap(Bitmap)` -> `Icon(Bitmap)`
- ImageFromStream
  - `ImageFromStream(...)` -> `Image(...)`
- MaskColour
  - _Problem_: wx.Colour hat keinen analogen Konstruktor?
- PyDropTarget
  - `PyDropTarget` -> `DropTarget`
  - `IconDisplayDropTarget`:
    - redundante Vererbung?
    - Woher kommt die Property `self.display`?
- PySimpleApp
  - `PySimpleApp` -> `App`
- PyValidator
  - `PyValidator` -> `Validator`
- SetCursor
  - sollte eigentlich _MISSING_ sein, aber existiert noch (ohne Depreciation!)
- SetBitmapSelected
  - nicht Deprecated in _wx.lib.buttons_
- SplashScreen
  - `wx.SplashScreen` -> `wx.adv.SplashScreen`
  - einige _SPLASH_-Konstanten mussten auch anders referenziert werden
- StockCursor
  - `StockCursor` -> `Cursor`
- Validator\_IsSilent
  - `Validator_IsSilent()` -> `Validator.IsSilent()`

wx.DC:

- BeginDrawing / EndDrawing
  - wxPython3 Doku:
  
  ```python
   # These have been deprecated in wxWidgets.  Since they never
   # really did anything to begin with, just make them be NOPs.
   def BeginDrawing(self):  pass
   def EndDrawing(self):  pass
  ```

  - beide entfernt
- GetResolution
  - `wx.PostScriptDC.(Get/Set)Resolution` existiert nicht mehr, bisher keine Migration gefunden
  - TODO
- Ok
  - `Ok` -> `IsOk`

wx.Window:

- GetSizeTuple
- SetBestFittingSize
  - existierende Lösung:

  ```python
    if wx.VERSION < (2, 8):
       window.SetBestFittingSize(wx.Size(50, 150))
    else:
       window.SetInitialSize(wx.Size(50, 150))
  ```

  - bisher nicht geändert
- SetDimensions?
  - mit IDE nicht gefunden
- SetToolTipString
  - Methode ist nicht deprecated - trotzdem geändert
  - fraglich ob Flag vergessen wurde oder Methode bestehen bleibt
- SetVirtualSizeHints
  - siehe Punkt `SetBestFittingSize`

Modules which have moved:

- SplashScreen
  - `wx.SplashScreen` -> `wx.adv.SplashScreen` (s.o.)

## Versionen

Bisheriges Prinzip:

```python
if wx.VERSION < (2,3):
  ...
```

Auch bei Sprung von 3.x auf 4.x so umsetzen?

## Weitere (undokumentierte) Migrationen

_Memo_: Nach Regex "[A-Z]+[a-z]+[A-Za-z]\*\_[A-Z]+[a-z]+[A-Za-z]\*" suchen ?

- PostScriptDC\_GetResolution
- PostScriptDC\_SetResolution

## Sonstiges

- gamera\_icons.getToolMenuBitmap existiert nicht: toolbar.py:74
- Code-Anleitungen in PyDoc anpassen (bei Verwendung alter API)
  - gui_support.py:39: wx.EmptyImage
- PyCharm-Issues:
  - toolbar.py:74 gamera_icons.getToolbarMenuBitmap() existiert nicht

## Progress

### WXP3

| Methode                      | Migration | Implementiert | Getestet | Anmerkungen |
|:-----------------------------|:---------:|:-------------:|:--------:|:------------|
| resize_window_virtual        | x | x | x | Test: Edit-Classifier Window |
| create_help_display          | x | x | x | Test: Docstring wird angezeigt |
| Calltip                      | x | x | x | Test(Shell): `import itertools` -> `itertool.count(` -> Enter |
| configure_icon_display_style | x | x | x | Test: Icons im 'Objects'-Bereich korrekt dargestellt |
| configure_print_dialog_data  | x | x | x | Test: Print dialog öffnet sich zu Bild |
| register_get_first_child     | x | x | x | Test: Beim Laden der Anwendung aufgerufen |
| register_set_scrollbars      | x | x | x | Test: Scrollbar-Funktion wird registriert |
| set_grid_line_colour         | x | x | x | Test: Gridline im Classif.-Display wird korrekt dargestellt |
| register_renderer_access     | x | x | x | Test: Beim Laden der Anwendung aufgerufen |
| init_image_handlers          | x | x | x | Test: Beim Laden der Anwendung aufgerufen |
| set_control_down             | x | x | x | Test: Aufgerufen wenn in Shell Up/Down gedrückt wird |

### WXP4

| Methode                      | Migration | Implementiert | Getestet | Anmerkungen |
|:-----------------------------|:---------:|:-------------:|:--------:|:---|
| BitmapFrom[Image/Icon]       | x | x | x | Test: Externes Bild in Programm laden |
| CustomDataFormat             | x | x | x | |
| Empty[Bitmap/Image]          | x | x | x | |
| IconFromBitmap               | x | x | x | Test: Icons werden allgemein angezeigt |
| ImageFromStream              | x | x | x | |
| MaskColour                   | x | x | o | In wxPython3 schon deprecated (use wx.Mask) |
| PyDropTarget                 | x | x | x | Test: Bilddatei in icon-display droppen |
| PySimpleApp                  | x | x | x | |
| PyValidator                  | x | x | x | Test: knn-editing -> Zahl-Validation klappt |
| SetCursor                    | o | o | o | wx.SetCursor und wx.Window.SetCursor gibts! |
| SetBitmapSelected            | o | o | o | existiert und nicht deprecated |
| StockCursor                  | x | x | o | |
| Validator\_IsSilent          | x | x | x | |
| BeginDrawing / EndDrawing    | x | x | x | |
| Ok                           | x | x | x | |
| GetSizeTuple                 | x | x | x | |
| SetBestFittingSize           | x | x | o | Bereits abgedeckt |
| SetDimensions                | x | x | x | |
| SetToolTipString             | x | x | x | Test: Tooltips werden angezeigt |
| SetVirtualSizeHints          | x | x | o | Bereits abgedeckt |
| SplashScreen + Konstanten    | x | x | x | Test: Wird zentriert beim Start angezeigt |
| PostScriptDC_Get/SetResol    | o | o | o | Funktion existiert auch in wxPython3 nicht |
| TreeCtrl#Get/SetPyData       | x | x | o | |
| Menu#AppendMenu              | x | x | x | Test: Submenus werden erzeugt |
| wx.SAVE                      | x | x | x | |
| wx.PYAPP_ASSERT_SUPPRESS     | x | x | x | |
| wx.grid.EVT_GRID_CELL_CHANGE | x | x | x | |
| PyGridCellRenderer           | x | x | x | |
| ListCtrl#SetStringItem       | x | x | x | |

- neue *gamera_icons.py*-Datei generieren: x
- Importänderungen nochmal prüfen (z.T. evtl. genutzte Imports entfernt): o
- Manchmal gibts im Edit-Classifier Bild eine horizontale Scrollbar - scheint Random zu sein? o
- wx.ImageList.AddIcon -> wx.ImageList.Add (Rückgabewert prüfen!) o
- wx.ImageList#InsertImageListItem -> wx.ImageList#InsertItem x
- neue Buffer-API zum Einlesen von Bildern verarbeiten (to_buffer), req. Python 2.7! x
  - Prüfung: `PyBuffer_Release` notwendig? o
- Umsetzung event.m_itemIndex o
- Umsetzung FlexGridSizer (knn_editing_display) Konstruktor-Überladung o

### Bugfixes

- *knn_editing_display.py*: ChoiceBox zeigt nun initial den ersten Algorithmus an
- *StatusDisplay.py:* line 44: (File -> Biollante...) wx.wx.LEFT -> 'module' object has no attribute 'wx'
- Doku->'Training Tutorial'->'Selecting Glyphs': Statt *Shift* muss *Ctrl* gedrückt werden