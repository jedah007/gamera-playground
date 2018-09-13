# Migration 

## Migration Guide

Link: [Migration-Guide](https://www.wxpython.org/Phoenix/docs/html/MigrationGuide.html)

### Zutreffende Abschnitte

- Font, Pen and Brush Styles
- wx.Image and Python Buffer Objects ??
- wx.DropSource
- The wxversion module ??


## Classic vs Phoenix

Link: [Classic-vs-Phoenix](https://www.wxpython.org/Phoenix/docs/html/classic_vs_phoenix.html#classic-vs-phoenix)

### Zutreffende Modifikationen

Functions and Classes Modifications

- BitmapFrom[Image/Icon]
- CustomDataFormat
- Empty[Bitmap/Icon/Image]
- IconFromBitmap
- ImageFromStream
- MaskColour
- PyDropTarget
- PySimpleApp
- PyValidator
- SetCursor
- SetBitmapSelected
- SplashScreen
- StockCursor
- Validator\_IsSilent

wx.DC:

- BeginDrawing
- EndDrawing
- Ok

wx.Window:

- GetSizeTuple
- SetBestFittingSize
- SetDimensions ?
- SetToolTipString
- SetVirtualSizeHints

Modules which have moved:

- SplashScreen
