

Count = 1024^2 = 1048576

Complexity = O(n^2)

int count = 0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++){
        count++;
    }
}
cout<<count<<endl;
Count = (1024^2-1024)/2) = 523,776

Complexity = O ((n^2-n)/2)

int count = 0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++){
        count++;
    }
}
cout<<count<<endl;
Count = (1024^3-1024^2)/2 = 536,346,624

Complexity = O((n^3-n^2)/2)

int count = 0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++){
        for(int k = 0; k < n; k++){
            count++;
        }
    }
}
cout<<count<<endl;
Count = 2* 1024 = 2048

Complexity = O(n)

int count=0;
int n = 1024;
for(int i = 0; i < 2*n; i++) {
    count++;
}
cout<<count<<endl;
Count = 2*(10246^2) =2,097,152

Complexity = O(n^2)

int count=0;
int n = 1024;
for(int i = 0; i < n; i++) {
    for(int j = 0; j < 2n; j++){
        count++;
    }
}
cout<<count<<endl;

Count = 524,800

Complexity = O(n+((n^2-n)/2)

int count=0;
int n = 1024;
for(int i = 0; i < n; i++) {
    count++;
}
for(int j = 0; j < n; j++){
    for(int k = 0; k < j; k++){
        count++;
    }
}
cout<<count<<edl;
Count = 11,264

Complexity = O(nlogn)

int count = 0;
int n = 1024;
int i = n;

while(i>0){
    for(int j = 0; j < n; j++){
        count++;
    }
    i /= 2;
    cout<<i<<endl;
}
cout<<count<<endl;
Comparisons = 10

Complexity = O(logn)

bool found = 0;
int n = 1024;
int i = n;

// assume loaded with random numbers
// and in ascending order.
int *A = new int[n];

// Whats most number of comparisons?
// Whats the complexity?
found = BinarySearch(A,n);

Count = 0
Complexity = O(log n)

int count = 0;
int n = 1024;

int i = n;
while(i>0){
    cout<<i<<endl;
    i /= 2;  
}
cout<<count<<endl;
