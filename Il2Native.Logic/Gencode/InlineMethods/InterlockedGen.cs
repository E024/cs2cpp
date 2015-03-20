﻿// --------------------------------------------------------------------------------------------------------------------
// <copyright file="InterlockedGen.cs" company="">
//   
// </copyright>
// <summary>
//   
// </summary>
// --------------------------------------------------------------------------------------------------------------------

namespace Il2Native.Logic.Gencode
{
    using System;
    using System.Globalization;
    using System.Linq;
    using CodeParts;
    using PEAssemblyReader;

    /// <summary>
    /// </summary>
    public static class InterlockedGen
    {
        /// <summary>
        /// </summary>
        /// <param name="opCodeMethodInfo">
        /// </param>
        /// <param name="oper">
        /// </param>
        /// <param name="attribs">
        /// </param>
        /// <param name="cWriter">
        /// </param>
        public static void IncDecInterlockBase(
            this OpCodePart opCodeMethodInfo,
            CWriter cWriter)
        {
            var writer = cWriter.Output;
            
            // TODO: finish ATOMIC +/-
            writer.Write("// TODO: finish ATOMIC +/-");
        }

        /// <summary>
        /// </summary>
        /// <param name="opCodeMethodInfo">
        /// </param>
        /// <param name="oper">
        /// </param>
        /// <param name="attribs">
        /// </param>
        /// <param name="extractValue">
        /// </param>
        /// <param name="cWriter">
        /// </param>
        public static void CompareExchange(
            this OpCodePart opCodeMethodInfo,
            CWriter cWriter,
            int[] operands)
        {
            var writer = cWriter.Output;
            var estimatedResult = cWriter.EstimatedResultOf(opCodeMethodInfo.OpCodeOperands[operands[2]]);
            cWriter.UnaryOper(writer, opCodeMethodInfo, operands[0], "compare_and_swap(", estimatedResult.Type.ToPointerType());
            cWriter.UnaryOper(writer, opCodeMethodInfo, operands[1], ", ", estimatedResult.Type);
            cWriter.UnaryOper(writer, opCodeMethodInfo, operands[2], ", ", estimatedResult.Type);
            writer.Write(")");
        }

        /// <summary>
        /// </summary>
        /// <param name="method">
        /// </param>
        /// <returns>
        /// </returns>
        public static bool IsInterlockedFunction(this IMethod method)
        {
            if (!method.IsStatic)
            {
                return false;
            }

            if (method.DeclaringType.FullName != "System.Threading.Interlocked")
            {
                return false;
            }

            switch (method.MetadataName)
            {
                case "Increment":
                case "Decrement":
                case "Exchange`1":
                case "Exchange":
                case "CompareExchange`1":
                case "CompareExchange":
                    return true;
            }

            return false;
        }

        /// <summary>
        /// </summary>
        /// <param name="method">
        /// </param>
        /// <param name="opCodeMethodInfo">
        /// </param>
        /// <param name="cWriter">
        /// </param>
        public static void WriteInterlockedFunction(
            this IMethod method,
            OpCodePart opCodeMethodInfo,
            CWriter cWriter)
        {
            switch (method.MetadataName)
            {
                case "Increment":
                    opCodeMethodInfo.IncDecInterlockBase(cWriter);
                    break;

                case "Decrement":
                    opCodeMethodInfo.IncDecInterlockBase(cWriter);
                    break;

                case "Exchange`1":
                case "Exchange":
                    ////opCodeMethodInfo.CompareExchange(cWriter, new[] { 0, 1 });
                    break;

                case "CompareExchange`1":
                case "CompareExchange":
                    opCodeMethodInfo.CompareExchange(cWriter, new[] { 0, 2, 1 }); 
                    break;
            }
        }
    }
}