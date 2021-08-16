# Concept of Fejix
![img](images/logo/png/fejix_logo-text-border.png)

<sub>Don't look inside `src` folder for now. It's just temporary, old and bad.</sub>

<sub>P.S. I would be grateful if somebody helped me with the logo - I don't draw very well. Currently it's an orchid.</sub>

# The ViLaSCo model

Widget is defined as a set of four parameters:

* __Visuals__ &mdash; a list of all graphical elements of the widget;
* __Layout__ &mdash; a set of rules that describe how the widget should be placed on a graphical display related to other widgets;
* __Script__ &mdash; program code that is to be executed if the user interacts with the widget (includes changes to the widget visuals and invokation of the program functionality controlled by the widget);
* __Content__ &mdash; a list of _children_ widgets tied to the _parent_ widget in order to be controlled and/or visually grouped;
  * __Static content__ &mdash; a fixed set of widgets needed to display the parent widget. It must be never changed (i.e. no widgets should be added or removed from the static content during the run time).


## Visuals &ndash; Elems

Visuals consist of _elems_ &ndash; the graphical primitives. Every elem has a _shape_ (form) and _fill_ (filling). Here are some examples of elems:

<svg xmlns="http://www.w3.org/2000/svg" width="10em" height="6em">
    <rect
        x ="0" y ="0" width="10em" height="3em" fill="yellow"/>
    <text x="0" y="4em" fill="magenta">
        Shape: rectange
    </text>
    <text x="0" y="5em" fill="magenta">
        Fill: soild color (yellow)
    </text>
</svg>

<svg xmlns="http://www.w3.org/2000/svg">
    <ellipse cx="4em" cy="1.5em" rx="4em" ry="1.5em" fill="green"/>
    <text x="0" y="4em" fill="magenta">
        Shape: ellipse
    </text>
    <text x="0" y="5em" fill="magenta">
        Fill: solid color (green)
    </text>
</svg>

<svg xmlns="http://www.w3.org/2000/svg">
    <defs>
        <pattern id="p1" patternUnits="userSpaceOnUse" width="7em" height="7em" viewBox="0 0 200 200">
            <image x="0" y="0" width="200" height="200" href="images/water.jpg"/>
        </pattern>
    </defs>
    <rect x="0" y="0" width="7em" height="3em" fill="url(#p1)" rx="1em" ry="0.5em"/>
    <text x="0" y="4em" fill="magenta">
        Shape: rectangle (radius-x: 1em, radius-y: 0.5em)
    </text>
    <text x="0" y="5em" fill="magenta">
        Fill: image (images&sol;water.jpg)
    </text>
</svg>
