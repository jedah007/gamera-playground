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
