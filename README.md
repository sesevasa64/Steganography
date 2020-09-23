# Steganography

This console application allows you to hide information in images or extract information from images. The principle of operation is to divide the image into groups of randomly selected pixels and change the least significant bits in the color components (R, G, B) of these pixels.

## Usage

### Required command line arguments

1. ```-mode {encrypt/decrypt}``` 
2. ```-i {image name}``` : Supported formats - jpg, png, bmp
3. ```-p {password}```: Password for correct encoding/decoding
4. ```-m {message}```: The message to be hidden for decrypt mode (if file mode not selected)

### Optional command line arguments

1. ```-f {file name}```: Used to save the message to a file if the encoding mode is selected or to read the message from the file if the decoding mode is selected.
You can write only ```-f``` then the default names will be used (ouput.txt, input.txt)

## Examples
<img src="https://drive.google.com/uc?export=view&id=18eFp0wDlBlZ2ThwuZ8TKrgRY04sTuwye" alt="Tiger image" style="float:" title="tiger.bmp" />

### Decrypting

```
test -mode decrypt -i tiger.bmp -p 123 -m "Message"
```

### Encrypting

```
test -mode encrypt -i tiger.bmp -p 123
Encrypted message: Message
```

## Errors

1. Password is incorrect
    ```
    test -mode encrypt -i tiger.bmp -p 321
    Password is incorrect!
    ```
2. Cant load image
    ```
    test -mode encrypt -i tihger.bmp -p 123  
    Cant load image!
    ```
3. Mode not selected
    ```
    test -mode -i tiger.bmp -p 123          
    Error: Mode is not selected!
    ```
4. Unknown mode
    ```
    test -mode f -i tiger.bmp -p 123 
    Error: Unknown mode!
    ```
