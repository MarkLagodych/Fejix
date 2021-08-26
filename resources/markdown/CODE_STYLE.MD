# Fejix code style rules:

[BACK (implementation README)](IMPL_README.MD)

[NEXT (compilation options)](CPL_OPTIONS.MD)

Fejix style is `camelCase` for normal identifiers and `SCREAMING_SNAKE_CASE` for macros.

## Normal identifiers
```
fj_fooBar
```

---------

## Macros / enumeration members
```
FJ_FOO_BAR
```

---------


## Header guards
```
_FJ_FILE_NAME_H
```

---------


## Fejix option macros
```
FJ_OPT_FOO_BAR
```

---------

All abbreviations must follow the style of normal words.
```
readHtmlDocumentation
useXmlConfiguration
processPhpScripts
guiFallbackTtfFont
```

---------

"namespaces" (prefixes like `fj_`, `wm_`) must be written in snake case. Thus:
```
fj_wm_closeAllWindowsAndShowBsod();
```



---------

## Braces

Braces should appear on their own lines, but for short expressions it can vary.
```c
void foo(bar_t bar, baz_t baz, int flags, ...)
{
    // ...
}

/** BUT **/

if (i > 3) {
    // ...
}
```

## Typedefs

Structures should be declared with a `typedef`, but enumerations not.