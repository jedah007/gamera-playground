# Versionierung

## Prüfungsarten

```python
if wx.VERSION >= (2, 5):
    ...
```

```python
if LooseVersion(wx.__version__) < LooseVersion('3.0'):
    ...
```

## ImportError vs VersionError

```python
try:
   import wxversion
   wxversion.select(["3.0", "2.9", "2.8", "2.6", "2.5", "2.4"])
except ImportError:
   from wxPython.wx import wxVERSION
   # Check that the version is correct
   if wxVERSION[:2] < (2, 4) or wxVERSION[:2] > (3, 0):
     raise RuntimeError("""This version of Gamera requires wxPython 2.4.x, 2.6.x, 2.8.x, 2.9.x, or 3.0.x.  However, it seems that you have wxPython %s installed."""
                      % ".".join([str(x) for x in wxVERSION]))
```

- müsste hier nicht (auch) ein VersionError abgefangen werden? -> wxversion.select-Doku

## Memos

- gamera_display:882 -> Alte if-Prüfung war unnötig?
