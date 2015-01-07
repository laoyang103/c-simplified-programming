/*
 * Copyright (c) 2007-2011, Lloyd Hilaiel <lloyd@hilaiel.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <yajl/yajl_parse.h>
#include <yajl/yajl_gen.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char buffer[1024];

static int reformat_null(void * ctx)
{
    printf("[0x%p] NULL\n", ctx);
    return 1;
}

static int reformat_boolean(void * ctx, int boolean)
{
    printf("[0x%p] BOOL: %d\n", ctx, boolean);
    return 1;
}

static int reformat_number(void * ctx, const char * s, size_t l)
{
    memcpy(buffer, s, l);
    buffer[l] = 0;
    printf("[0x%p] NUMBER: %s\n", ctx, buffer);
    return 1;
}

static int reformat_string(void * ctx, const unsigned char * stringVal,
                           size_t stringLen)
{
    memcpy(buffer, stringVal, stringLen);
    buffer[stringLen] = 0;
    printf("[0x%p] STRING: %s\n", ctx, buffer);
    return 1;
}

static int reformat_map_key(void * ctx, const unsigned char * stringVal,
                            size_t stringLen)
{
    memcpy(buffer, stringVal, stringLen);
    buffer[stringLen] = 0;
    printf("[0x%p] MAP_KEY: %s\n", ctx, buffer);
    return 1;
}

static yajl_callbacks callbacks = {
    reformat_null,
    reformat_boolean,
    NULL,
    NULL,
    reformat_number,
    reformat_string,
    NULL,
    reformat_map_key,
    NULL,
    NULL,
    NULL
};

int 
main(int argc, char ** argv)
{
    yajl_handle hand;
    static unsigned char fileData[10];
    /* generator config */
    yajl_status stat;
    size_t rd;
    int retval = 0;

    /* ok.  open file.  let's read and parse */
    hand = yajl_alloc(&callbacks, NULL, (void *)0x1122);
    /* and let's allow comments by default */
    yajl_config(hand, yajl_allow_comments, 1);

    for (;;) {
        rd = fread((void *) fileData, 1, sizeof(fileData) - 1, stdin);

        if (rd == 0) {
            if (!feof(stdin)) {
                fprintf(stderr, "error on file read.\n");
                retval = 1;
            }
            break;
        }
        fileData[rd] = 0;

        printf("%s\n", fileData);
        stat = yajl_parse(hand, fileData, rd);

        if (stat != yajl_status_ok) break;
    }


    stat = yajl_complete_parse(hand);

    if (stat != yajl_status_ok) {
        unsigned char * str = yajl_get_error(hand, 1, fileData, rd);
        fprintf(stderr, "%s", (const char *) str);
        yajl_free_error(hand, str);
        retval = 1;
    }

    yajl_free(hand);

    return retval;
}
