# cmykvis
## A hastily-thrown-together CMYK visualization tool.

## Maths:
```
C, M, Y, and K are percentages, so if you store them as integers, be sure to divide them by 100.
R = 255 * (1-C) * (1-K)
G = 255 * (1-M) * (1-K)
B = 255 * (1-Y) * (1-K)
```

## Dependencies
- raylib

## License
This project is WTFPL-licensed.
