# Fixed-Point Conversion

Fixed-Point numbers are a convenient way to represent fractional numbers using a fixed number of bits. In fixed-point representation, the binary point is analogous to the decimal point in base-ten numbers but positioned differently in binary.

## The Binary Point

The Binary Point represents the boundary between the whole number and fractional parts of the fixed-point number. Although there's no distinct symbol for the Binary Point in binary representation, we conceptually place it at a fixed location within the number. For instance, in a 32-bit number, we can assume the Binary Point is between bits 15 and 16, with 16 bits dedicated to the whole number part and 16 bits to the fractional part. The most significant bit in the whole number field is often reserved for the sign, leaving 15 bits for the magnitude.

## Place Value Method

Not all numbers can be exactly represented in fixed-point form, so we use the closest approximation. The place value method allows us to determine the value of a fixed-point number.

For example, consider the following fixed-point representation:

`32 + 8 + 2 + 1 + 0.25 + 0.03125 + 0.0078125 + 0.00390625 = 43.2869375`

## Repeated Multiplication

To convert a decimal fraction to a binary fraction in fixed-point form, you can use the repeated multiplication technique. Here's a simple procedure:

1. Multiply the fractional part of the number by 2.
2. Take the integer part of the result (either 1 or 0) as the next bit.
3. Repeat this process until you obtain the desired number of bits to the right of the binary point.

For instance, to convert the decimal fraction 0.3568 into a fixed-point binary representation with 8 bits to the right of the binary point:

`0.3568 is approximately equal to 0.01011011 in fixed-point binary.`



This process continues until you have the required number of bits to represent the fraction.

## Example: Conversion from Float to Fixed-Point

Let's consider an example where we convert a floating-point number to a fixed-point number.

### Step 1: Start with a Floating-Point Number

Suppose we have the floating-point number 5.75.

### Step 2: Convert to Binary

First, convert the whole part (5) and the fractional part (0.75) to binary:

- The whole part (5) in binary is 101.
- The fractional part (0.75) in binary is 0.11.

### Step 3: Combine Binary Parts

Combine the binary whole part and fractional part:

- `5.75` in binary is `101.11`.

### Step 4: Fixed-Point Conversion

Now, assume we want to represent this number in a fixed-point format with 4 bits to the right of the binary point:

- The whole part is `101`, and the fractional part is `11`. To represent it in fixed-point form with 4 bits for the fractional part, we might need to truncate or round.

- The fixed-point representation with 4 bits to the right of the binary point is `101.1100`.

