#include <stdio.h>
#include <stdlib.h>

#include <htslib/sam.h>

int main(int argc, char **argv)
{
    htsFile *fp = NULL;
    bam_hdr_t *hdr = NULL;
    bam1_t *b = NULL;

    fp = hts_open((argc > 1)? argv[1] : "-", "r");
    if (fp == NULL) goto error;

    hdr = sam_hdr_read(fp);
    if (hdr == NULL) goto error;

    b = bam_init1();
    if (b == NULL) goto error;

    unsigned long long n = 0;
    int ret;
    while ((ret = sam_read1(fp, hdr, b)) >= 0)
        n++;

    if (ret < -1) goto error;

    bam_destroy1(b);
    bam_hdr_destroy(hdr);
    hts_close(fp);

    printf("%llu records\n", n);

    return EXIT_SUCCESS;

error:
    perror("tinycount failed");
    if (b) bam_destroy1(b);
    if (hdr) bam_hdr_destroy(hdr);
    if (fp) hts_close(fp);
    return EXIT_FAILURE;
}
