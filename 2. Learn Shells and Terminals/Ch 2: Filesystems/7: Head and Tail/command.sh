head -n 6 private/transactions/2023.csv >>./read.txt
tail -n 5 private/transactions/2023.csv >>./read.txt
cat -p read.txt
rm read.txt
