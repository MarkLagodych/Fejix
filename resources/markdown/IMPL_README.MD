# Fejix implementation

[BACK (concept README)](../../README.MD)

See notes about [code style](CODE_STYLE.MD) and [compilation options](CPL_OPTIONS.MD)

## How to build

Fejix uses [Xmake](https://xmake.io) build system.

1.  Install Xmake using one of the following commands:

    in bash:
    ```bash
    bash <(curl -fsSL https://xmake.io/shget.text)
    ```

    ```bash
    bash <(wget https://xmake.io/shget.text -O -)
    ```

    in powershell:
    ```powershell
    Invoke-Expression (Invoke-Webrequest 'https://xmake.io/psget.text' -UseBasicParsing).Content
    ```

2. Configure Fejix:
    
    via Xmake GUI configuration tool

    ```bash
    xmake config --menu
    ```

    via command line (see also [build options](#build-options)):

    ```bash
    xmake config --option1=value1 --option2=value2 ...
    ```

3.  Build Fejix:
    ```bash
    xmake build fejix
    ```

## Description

Yet almost nothing has been done... :roll_eyes: But it is coming soon! :smiley:

## Build options

Option | Meaning | Possible values | Default value
------ | ------- | --------------- | -------------
backend | The drawing library | SDL2/gfx | SDL2/gfx