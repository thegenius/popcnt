##This is a generic version of bit count:  
    use popcnt instruction on x86-64 platform  
    use generic software algorithm on other platforms

##The only need put the popcnt.h in your project and include it!

##API:  
    size_t popcnt_u8 (uint8_t v);  
    size_t popcnt_u16 (uint16_t v);  
    size_t popcnt_u32 (uint32_t v);  
    size_t popcnt_u64 (uint64_t v);
