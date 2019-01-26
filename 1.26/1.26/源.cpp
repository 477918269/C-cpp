void *memCpy(void *dest, const void *src, size_t n)
{
	if (NULL == dest || NULL == src || n < 0)
		return NULL;
	char *tempDest = (char *)dest;
	char *tempSrc = (char *)src;

	while (n-- > 0)
		*tempDest++ = *tempSrc++;
	return dest;
}
