/****************************************************************************
 *
 * MODULE:             http parse.h
 *
 * COMPONENT:          home kit interface
 *
 * REVISION:           $Revision:  1.0$
 *
 * DATED:              $Date: 2017-01-11 15:13:17 +0100 (Fri, 12 Dec 2016 $
 *
 * AUTHOR:             PCT
 *
 ****************************************************************************
 *
 * Copyright panchangtao@gmail.com 2017. All rights reserved
 *
 ***************************************************************************/
/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/
#include "http_handle.h"

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
#define DBG_HTTP 1
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/
static char *pcStrtokString(char *pcBuf, char *pcStart, char *pcEnd);
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
teHttpStatus eHttpParser(char *pBuf, uint16 u16Len, tsHttpEntry *psHttpEntry)
{
    CHECK_POINTER(psHttpEntry, E_HTTP_PARSER_ERROR);

    char *psHeader = strtok(pBuf, "\r\n");
    CHECK_POINTER(psHeader, E_HTTP_PARSER_ERROR);

    char *psHost = strtok(NULL, "\r\n");
    CHECK_POINTER(psHost, E_HTTP_PARSER_ERROR);

    char *psContentLen = strtok(NULL, "\r\n");
    CHECK_POINTER(psContentLen, E_HTTP_PARSER_ERROR);

    char *psContentType = strtok(NULL, "\r\n");
    CHECK_POINTER(psContentType, E_HTTP_PARSER_ERROR);

    char *psContentData = strtok(NULL, "\r\n");
    if(psContentData == NULL){
        memset(psHttpEntry->acContentData, 0, sizeof(psHttpEntry->acContentData));
    } else {
        memcpy(psHttpEntry->acContentData, psContentData, sizeof(psHttpEntry->acContentData));
    }


    char *psMethod = strtok(psHeader, " ");
    CHECK_POINTER(psMethod, E_HTTP_PARSER_ERROR);
    memcpy(psHttpEntry->acHttpMethod, psMethod, sizeof(psHttpEntry->acHttpMethod));
    char *psDirectory = strtok(NULL, " ");
    CHECK_POINTER(psDirectory, E_HTTP_PARSER_ERROR);
    memcpy(psHttpEntry->acDirectory, psDirectory, sizeof(psHttpEntry->acDirectory));
    char *psHttpVer = strtok(NULL, " ");
    CHECK_POINTER(psHttpVer, E_HTTP_PARSER_ERROR);
    memcpy(psHttpEntry->acHttpVersion, psHttpVer, sizeof(psHttpEntry->acHttpVersion));
    printf("Method:%s,Dir:%s,Version:%s\n", psHttpEntry->acHttpMethod, psHttpEntry->acDirectory, psHttpEntry->acHttpVersion);

    char *psLen = strtok(psContentLen, ":");
    psLen = strtok(NULL, ":");
    CHECK_POINTER(psLen, E_HTTP_PARSER_ERROR);
    psHttpEntry->u16ContentLen = (uint16)atoi(psLen);
    printf("Len:%d\n", psHttpEntry->u16ContentLen);

    char *psType = strtok(psContentType, ":");
    psType = strtok(NULL, ":");
    CHECK_POINTER(psType, E_HTTP_PARSER_ERROR);
    memcpy(psHttpEntry->acContentType, psType, sizeof(psHttpEntry->acContentType));
    printf("Type:%s\n", psHttpEntry->acContentType);

    return E_HTTP_PARSER_OK;
}

teHttpStatus eHttpResponse(int iSockFd, tsHttpEntry *psHttpEntry, char *pBuffer, uint16 u16Length)
{
    char temp[MABF] = {0};
    snprintf(temp, sizeof(temp), "HTTP/1.1 %d OK\r\nContent-Type:%s\r\nContent-Length: %d\r\n\r\n",
             psHttpEntry->iHttpStatus, psHttpEntry->acContentType, u16Length);

    DBG_vPrintln(DBG_HTTP, "%s", temp);
    ssize_t ret = send(iSockFd, temp, strlen(temp), 0);
    if(ret == -1){
        ERR_vPrintln(T_TRUE, "send failed:%s", strerror(errno));
    }
    ret = send(iSockFd, pBuffer, u16Length, 0);
    if(ret == -1){
        ERR_vPrintln(T_TRUE, "send failed:%s", strerror(errno));
    }
    return E_HTTP_PARSER_OK;
}
/****************************************************************************/
/***        Local    Functions                                            ***/
/****************************************************************************/
static char *pcStrtokString(char *pcBuf, char *pcStart, char *pcEnd)
{
    CHECK_POINTER(pcBuf, NULL);
    CHECK_POINTER(pcStart, NULL);
    CHECK_POINTER(pcEnd, NULL);

    char *pIndexStart = strstr(pcBuf, pcStart);
    char *pIndexEnd = strstr(pcBuf, pcEnd);
    printf("S:%s,E:%s\n", pIndexStart, pIndexEnd);

    return NULL;
}