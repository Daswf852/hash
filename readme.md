# Hash
a header only thingamadoodle for hashing other thingamadoodles  

## Usage
You can just include the files in lib/hash or do an add_subdirectory preceded by a git clone/submodule add
```cpp
#include <memory>

#include "hash/sha1.hpp"
#include "hash/sha2.hpp"

int main() {
    Hash::Sha1 digest;
    
    digest.Update("asdasd"); //const char * update
    
    std::string str{"asdasd2"};
    digest.Update({str.cbegin(), str.cend()}); //string view update
    
    std::string hash = digest.Final();
    
    //polymorphism:
    Hash::Digest &genericDigest = digest;
    std::unique_ptr<Hash::Digest> uniqueGenericDigest = std::make_unique<Hash::Md5>();
    //etc.
}
```

## Functions
 - Md5  
 - Sha0, Sha1  
 - Sha224, Sha256, Sha384, Sha512  
^ not capitalised because these are the class' names i guess

## To-Do

 - Reduce spaghetti
 - Implement other functions
     - Sha512/t
     - Sha3
     - Md2 and Md4 maybe?
     - BLAKE
     - Grøstl
     - Skein
 - Improve performance
 - Use less reinterpret_casts
    