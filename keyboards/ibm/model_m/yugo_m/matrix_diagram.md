# Matrix Diagram for Yugo-M (Model M replacment controller)

```
┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
│02 │   │23 │24 │14 │04 │ │06 │08 │19 │29 │ │26 │36 │3B │3C │ │3F │4F │6E │
└───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
│22 │32 │33 │34 │35 │25 │27 │37 │38 │39 │3A │2A │28 │46 │16 │ │2C │2E │2D │ │6B │6C │6D │7D │
├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┤ ├───┼───┼───┤ ├───┼───┼───┼───┤   ┌───┐
│12   │42 │43 │44 │45 │15 │17 │47 │48 │49 │4A │1A │18 │56   │ │2B │3E │3D │ │4B │4C │4D │4E │   │   │
├────┬┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤ └───┴───┴───┘ ├───┼───┼───┼───┤   │4E │ 2u Numpad Plus
│13  ┊ │52 │53 │54 │55 │05 │07 │57 │58 │59 │5A │0A │66      │               │1B │1C │1D │1E │   │   │
├────┼─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬──────┤     ┌───┐     ├───┼───┼───┼───┤   ├───┤
│11  │03 │62 │63 │64 │65 │75 │77 │67 │68 │69 │7A │78 │61    │     │0E │     │5B │5C │5D │5E │   │   │
├────┴┬──┴┬──┴──┬┴───┴───┴───┴───┴───┴───┴──┬┴───┴┬──┴┬─────┤ ┌───┼───┼───┐ ├───┼───┼───┼───┤   │5E │ 2u Numpad Enter
│20   │   │0F   │76                         │7F   │   │60   │ │7E │7B │7C │ │0B │0C │0D │5F │   │   │
└─────┘   └─────┴───────────────────────────┴─────┘   └─────┘ └───┴───┴───┘ └───┴───┴───┴───┘   └───┘
                                                    ┌───────┐
                                       2u Backspace │16     │
                                                    └─┬─────┤
                                                      │     │
                                         ISO Enter ┌──┴┐66  │
                                                   │6A │    │
┌────────┐                                       ┌─┴───┴────┤               ┌───────┐
│11      │ 2.25u LShift             2.75u RShift │61        │               │0B     │ 2u Numpad Zero
└────────┘                                       └──────────┘               └───────┘
```