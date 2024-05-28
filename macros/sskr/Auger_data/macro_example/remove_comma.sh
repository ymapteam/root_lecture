// ----------------------- //
// remove_comma.sh
// Author: S. Sakurai
// Date  : May 29 2024
// Usage : bash remove_comma.sh <CSV file>
// Pickup any columns from a CSV file.
// ----------------------- //

# type the number of columns for 000
# Example --> cat $1 | sed -e "s/,/ /g" | sed '1d' | awk '{print $15,$16}'
cat $1 | sed -e "s/,/ /g" | sed '1d' | awk '{print $000,$000}'